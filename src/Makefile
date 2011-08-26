include ../make.rules
SRCS=$(shell ls *.c)
OBJS=$(SRCS:%.c=%.o)


openhack: $(OBJS) ../config.h
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o openhack

clean:
	rm $(OBJS)
	rm openhack

%.c: ../include/%.h

