
TARGETS	=	ForkJoin		\
			ForkJoinPerf	\
			ForkJoinVar		\
			Lock			\
			PCreate			\
			RWLockScale

all: $(TARGETS)

ForkJoin: Demo_04.02_ForkJoin.c Tools.h
	gcc -o ForkJoin Demo_04.02_ForkJoin.c

ForkJoinVar: Demo_04.03_ForkJoinVar.c Tools.h
	gcc -o ForkJoinVar Demo_04.03_ForkJoinVar.c

ForkJoinPerf: Demo_04.04_ForkJoinPerf.c
	gcc -o ForkJoinPerf Demo_04.04_ForkJoinPerf.c

PCreate: Demo_04.05_PCreate.c Tools.h
	gcc -o PCreate Demo_04.05_PCreate.c -lpthread

Lock: Demo_04.06_Lock.c Tools.h
	gcc -o Lock Demo_04.06_Lock.c -lpthread

RWLockScale: Demo_04.07_RWLockScale.c Tools.h
	gcc -o RWLockScale Demo_04.07_RWLockScale.c -lpthread

clean:
	rm -f $(TARGETS) *.o
