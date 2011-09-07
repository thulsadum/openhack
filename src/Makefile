include ../make.rules
SRCS=$(shell ls *.c)
OBJS=$(SRCS:%.c=%.o)


openhack: $(OBJS) ../config.h
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o openhack

clean:
	rm $(OBJS)
	rm $(SRCS:.c=.d)
	rm openhack

include $(SRCS:.c=.d)

