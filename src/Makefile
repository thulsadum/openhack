INCLUDE=-I..
include ../make.rules
SRCS=$(shell ls *.c)
OBJS=$(SRCS:%.c=%.o)


openhack: compile
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o openhack

compile: $(OBJS) ../config.h

clean:
	rm $(OBJS)
	rm $(SRCS:.c=.d)
	rm openhack

include $(SRCS:.c=.d)

