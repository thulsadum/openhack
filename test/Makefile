INCLUDE=-I..
include ../make.rules
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
EXECS=$(SRCS:%.c=%)

test:  $(EXECS) ../config.h
	@for t in $(EXECS); do echo running test: $$t && ./$$t || break ; done

list: list.o ../src/list.o
	$(CC) $(CFLAGS) list.o ../src/list.o -o list

stack: stack.o ../src/list.o ../src/stack.o
	$(CC) $(CFLAGS) stack.o ../src/list.o ../src/stack.o -o stack

queue: queue.o ../src/list.o ../src/stack.o
	$(CC) $(CFLAGS) queue.o ../src/list.o ../src/stack.o -o queue

clean:
	rm *.o
	rm *.d
	rm $(EXECS)

include $(SRCS:.c=.d)

