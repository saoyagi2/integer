CFLAGS  = -O3 -Wall

GMPCFLAGS  = -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= emirp palindromicprime primegen primedigit mersenne fermat twinprime brotherprime

.PHONY: all clean test


all:	$(OUTS)

emirp:	emirp.c
	cc $(CFLAGS) -o emirp emirp.c

palindromicprime:	palindromicprime.c
	cc $(CFLAGS) -o palindromicprime palindromicprime.c

primegen:	primegen.c
	cc $(GMPCFLAGS) -o primegen primegen.c

primedigit:	primedigit.c
	cc $(CFLAGS) -o primedigit primedigit.c

mersenne:	mersenne.c
	cc $(GMPCFLAGS) -o mersenne mersenne.c

fermat:	fermat.c
	cc $(GMPCFLAGS) -o fermat fermat.c

twinprime:	twinprime.c
	cc $(CFLAGS) -o twinprime twinprime.c

brotherprime:	brotherprime.c
	cc $(CFLAGS) -o brotherprime brotherprime.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
