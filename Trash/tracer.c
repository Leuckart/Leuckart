/**************************************************
	> File Name:  tracer.c
	> Author:     Leuckart
	> Time:       2020-03-19 03:38
**************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <sys/mman.h>

typedef struct handle
{
	Elf64_Ehdr *ehdr;
	Elf64_Phdr *phdr;
	Elf64_Shdr *shdr;
	uint8_t *mem;
	char *symname;
	Elf64_Addr symaddr;
	struct user_regs_struct pt_reg;
	char *exec;
} handle_t;

Elf64_Addr lookup_symbol(handle_t *, const char *);

int main(int argc, char **argv, char **envp)
{
	int fd;
	handle_t h;
	struct stat st;
	long trap, orig;
	int status, pid;
	char *args[2];

	if (argc < 3)
	{
		printf("Usage: %s <program> <function>\n", argv[0]);
		exit(0);
	}

	if ((h.exec = strdup(argv[1])) == NULL)
	{
		perror("strdup");
		exit(-1);
	}

	args[0] = h.exec;
	args[1] = NULL;
	if ((h.symname = strdup(argv[2])) == NULL)
	{
		perror("strdup");
		exit(-1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("open");
		exit(-1);
	}

	if (fstat(fd, &st) < 0)
	{
		perror("fstat");
		exit(-1);
	}

	h.mem = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (h.mem == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}

	h.ehdr = (Elf64_Ehdr *)h.mem;
	h.phdr = (Elf64_Phdr *)(h.mem + h.ehdr->e_phoff);
	h.shdr = (Elf64_Shdr *)(h.mem + h.ehdr->e_shoff);

	if (h.mem[0] != 0x7f || strcmp((char *)&h.mem[1], "ELF")) // Leuckart
	{
		printf("%s is not an ELF file.\n", h.exec);
		exit(-1);
	}

	if (h.ehdr->e_type != ET_EXEC)
	{
		printf("%s is not an ELF executable.\n", h.exec);
		exit(-1);
	}

	if (h.ehdr->e_shstrndx == 0 || h.ehdr->e_shoff == 0 || h.ehdr->e_shnum == 0)
	{
		printf("Section header table not found.\n");
		exit(-1);
	}

	if ((h.symaddr = lookup_symbol(&h, h.symname)) == 0)
	{
		printf("Unable to find symbol: %s not found in executable.\n", h.symname);
		exit(-1);
	}

	close(fd);
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	if (pid == 0)
	{
		if (ptrace(PTRACE_TRACEME, pid, NULL, NULL) < 0)
		{
			perror("PTRACE_TRACEME");
			exit(-1);
		}
		execve(h.exec, args, envp);
		exit(0);
	}
	wait(&status);
	printf("Beginning analysis of pid: %d at %lx.\n", pid, h.symaddr);

	return 0;
}
