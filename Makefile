OBJS = sum_array.o
PROG = test

all: $(PROG)

%.o : %.s
	as -o $@ $<

$(PROG): $(PROG).c $(OBJS)
	gcc -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
