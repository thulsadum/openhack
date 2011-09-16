INCLUDE=-I..
include ../make.rules
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
EXECS=$(SRCS:%.c=%)

test:  $(EXECS) ../config.h
	@for t in $(EXECS); do echo running test: $$t && ./$$t || break ; done

list: list.o ../src/core/list.o
	$(LINK) list.o ../src/core/list.o -o list

stack: stack.o ../src/core/list.o ../src/core/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/core/list.o ../src/core/deque.o -o $@

queue: queue.o ../src/core/list.o ../src/core/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/core/list.o ../src/core/deque.o -o $@

deque: deque.o ../src/core/list.o ../src/core/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/core/list.o ../src/core/deque.o -o $@

prototype: prototype.o ../src/core/list.o ../src/core/deque.o
	$(LINK) $(CFLAGS) $@.o ../src/core/list.o ../src/core/deque.o -o $@

clean:
	-rm *.o
	-rm *.d
	-rm $(EXECS)

-include $(SRCS:.c=.d)

