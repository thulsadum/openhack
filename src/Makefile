INCLUDE=-I..
include ../make.rules
SRCS=$(shell ls *.c)
OBJS=$(SRCS:%.c=%.o)


openhack: compile
	$(LINK) $(OBJS) $(LDFLAGS) -o openhack

compile: $(OBJS) ../config.h

clean:
	-rm $(SRCS:.c=.d)
	-rm $(OBJS)
	-rm openhack

-include $(SRCS:.c=.d)

