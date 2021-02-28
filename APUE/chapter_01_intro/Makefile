
TARGETS	=	ls		\

all: $(TARGETS)

ls: ls.c ../error.c ../apue.h
	gcc -o ls ls.c ../error.c

clean:
	rm -f $(TARGETS) *.o
