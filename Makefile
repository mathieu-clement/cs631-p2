CFLAGS=-g -std=c99 -O2 -Wall -Werror -I.
LDFLAGS=
CC=clang
OBJS  = sum_array.o find_max.o fib_rec.o fib_rec.o find_str.o
PROGS = sum_test find_max_test fib_rec_test fib_iter_test find_str_test
DEPS = utils.o

all: $(PROGS)

%.o : %.s
	as -o $@ $<

deps.o : deps.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

sum_test: sum_test.c sum_array.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

find_max_test: find_max_test.c find_max.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

fib_rec_test: fib_rec_test.c fib_rec.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

fib_iter_test: fib_iter_test.c fib_iter.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

find_str_test: find_str_test.c find_str.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(PROGS)
	@$(foreach prog,$(PROGS), ./$(prog);)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)
