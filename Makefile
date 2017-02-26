CFLAGS=-g -std=c99 -Wall -Werror -I.
LDFLAGS=
CC=clang
OBJS  = sum_array.o
PROGS = sum_test

all: $(PROGS)

%.o : %.s
	as -o $@ $<

sum_test: sum_test.c sum_array.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(PROGS)
	@$(foreach prog,$(PROGS), ./$(prog);)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGS)
