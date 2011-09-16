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
	$(LINK) $(CFLAGS) $@.o ../src/list.o ../src/deque.o -o $@

queue: queue.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/list.o ../src/deque.o -o $@

deque: deque.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/list.o ../src/deque.o -o $@

prototype: prototype.o ../src/list.o ../src/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/list.o ../src/deque.o -o $@

clean:
	-rm *.o
	-rm *.d
	-rm $(EXECS)

-include $(SRCS:.c=.d)

