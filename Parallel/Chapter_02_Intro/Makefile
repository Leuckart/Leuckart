
TARGETS	=	InitRace		\
			InitRacePerf	\
			LockInc			\
			NakedInc		\
			PerThreadInc	\
			ThreadCreate

all: $(TARGETS)

InitRace: Demo_02.01_InitRace.c Tools.h
	gcc -g -Wall -o InitRace Demo_02.01_InitRace.c -lpthread

InitRacePerf: Demo_02.02_InitRacePerf.c Tools.h
	gcc -g -Wall -o InitRacePerf Demo_02.02_InitRacePerf.c -lpthread

LockInc: Demo_02.03_LockInc.c Tools.h
	gcc -g -Wall -o LockInc Demo_02.03_LockInc.c -lpthread

NakedInc: Demo_02.04_NakedInc.c Tools.h
	gcc -g -Wall -o NakedInc Demo_02.04_NakedInc.c -lpthread

PerThreadInc: Demo_02.05_PerThreadInc.c Tools.h
	gcc -g -Wall -o PerThreadInc Demo_02.05_PerThreadInc.c -lpthread

ThreadCreate: Demo_02.06_ThreadCreate.c Tools.h
	gcc -g -Wall -o ThreadCreate Demo_02.06_ThreadCreate.c -lpthread

clean:
	rm -f $(TARGETS) *.o
