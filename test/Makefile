INCLUDE=-I..
include ../make.rules
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
EXECS=$(SRCS:%.c=%)

test:  $(EXECS)
	@for t in $(EXECS); do echo $$t && ./$$t ; done

$(EXECS) : $(OBJS) $(OBJS:%=../src/%) ../config.h
	$(CC) $(CFLAGS) ../src/$@.o $@.o $(LDFLAGS) -o $@

clean:
	rm *.o
	rm *.d
	rm $(EXECS)

include $(SRCS:.c=.d)

