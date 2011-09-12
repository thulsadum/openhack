INCLUDE=-I..
include ../make.rules
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
EXECS=$(SRCS:%.c=%)

test:  $(EXECS) ../config.h
	@for t in $(EXECS); do echo running test: $$t && ./$$t || break ; done

list: list.o ../src/list.o
	$(LINK) list.o ../src/list.o -o list

stack: stack.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) stack.o ../src/list.o ../src/deque.o -o stack

queue: queue.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) queue.o ../src/list.o ../src/deque.o -o queue

deque: deque.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) deque.o ../src/list.o ../src/deque.o -o deque

clean:
	rm *.o
	rm *.d
	rm $(EXECS)

-include $(SRCS:.c=.d)

