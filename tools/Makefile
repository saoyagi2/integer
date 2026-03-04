CFLAGS	= -O3 -Wall

OUTS	= primes2diff diff2primes

.PHONY: all clean test


all:	$(OUTS)

primes2diff:	primes2diff.c
	cc $(CFLAGS) -o primes2diff primes2diff.c

diff2primes:	diff2primes.c
	cc $(CFLAGS) -o diff2primes diff2primes.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
