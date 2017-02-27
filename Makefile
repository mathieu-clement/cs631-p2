CFLAGS=-g -std=c99 -Wall -Werror -I.
LDFLAGS=
CC=clang
OBJS  = sum_array.o find_max.o fib_rec.o fib_rec.o
PROGS = sum_test find_max_test fib_rec_test fib_iter_test

all: $(PROGS)

%.o : %.s
	as -o $@ $<

sum_test: sum_test.c sum_array.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

find_max_test: find_max_test.c find_max.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

fib_rec_test: fib_rec_test.c fib_rec.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

fib_iter_test: fib_iter_test.c fib_iter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(PROGS)
	@$(foreach prog,$(PROGS), ./$(prog);)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)
