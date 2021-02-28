
TARGETS = CountNonAtomic	\
	CountAtomic				\
	CountStat				\
	CountStatAtomic			\
	CountStatEventual		\
	CountEnd				\
	CountLim				\
	CountLimApp				\
	CountLimAtomic			\
	CountLimSig
#	count_limd \
	count_stack \
	count_tstat

all: $(TARGETS)

CountNonAtomic: Demo_05.01_CountNonAtomic.c Tools.h CountTorture.h
	gcc -o CountNonAtomic Demo_05.01_CountNonAtomic.c -lpthread

CountAtomic: Demo_05.02_CountAtomic.c Tools.h CountTorture.h
	gcc -o CountAtomic Demo_05.02_CountAtomic.c -lpthread

CountStat: Demo_05.03_CountStat.c Tools.h CountTorture.h
	gcc -o CountStat Demo_05.03_CountStat.c -lpthread

CountStatAtomic: Demo_05.04_CountStatAtomic.c Tools.h CountTorture.h
	gcc -o CountStatAtomic Demo_05.04_CountStatAtomic.c -lpthread

CountStatEventual: Demo_05.05_CountStatEventual.c Tools.h CountTorture.h
	gcc -o CountStatEventual Demo_05.05_CountStatEventual.c -lpthread

CountEnd: Demo_05.06_CountEnd.c Tools.h CountTorture.h
	gcc -o CountEnd Demo_05.06_CountEnd.c -lpthread

# CountEndRCU: Demo_05.07_CountEndRCU.c Tools.h CountTorture.h rcu_nest32.c rcu_nest32.h
#	gcc -o CountEndRCU Demo_05.07_CountEndRCU.c -lpthread

CountLim: Demo_05.08_CountLim.c Tools.h LimTorture.h
	gcc -o CountLim Demo_05.08_CountLim.c -lpthread

CountLimApp: Demo_05.09_CountLimApp.c Tools.h LimTorture.h
	gcc -o CountLimApp Demo_05.09_CountLimApp.c -lpthread

CountLimAtomic: Demo_05.10_CountLimAtomic.c Tools.h LimTorture.h
	gcc -o CountLimAtomic Demo_05.10_CountLimAtomic.c -lpthread

CountLimSig: Demo_05.11_CountLimSig.c Tools.h LimTorture.h
	gcc -o CountLimSig Demo_05.11_CountLimSig.c -lpthread

# count_limd: count_limd.c Tools.h LimTorture.h
#	$(CC) $(GCC_ARGS) $(CFLAGS) -o count_limd count_limd.c -lpthread

# count_stack: count_stack.c Tools.h CountTorture.h
#	$(CC) $(GCC_ARGS) $(CFLAGS) -o count_stack count_stack.c -lpthread

# count_tstat: count_tstat.c Tools.h CountTorture.h
#	$(CC) $(GCC_ARGS) $(CFLAGS) -o count_tstat count_tstat.c -lpthread

clean:
	rm -f $(TARGETS) *.o
