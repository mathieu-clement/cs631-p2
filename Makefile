OBJS  = sum_array.o
PROGS = sum_test

all: $(PROGS)

%.o : %.s
	as -o $@ $<

sum_test: sum_test.c sum_array.o
	gcc -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)
