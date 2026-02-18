CFLAGS  = -O3 -Wall

GMPCFLAGS  = -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= emirp palindromicprime palindromicprime2 primegen primedigit primedigit2 mersenne fermat twinprime twinprime2 brotherprime brotherprime2

.PHONY: all clean test


all:	$(OUTS)

emirp:	emirp.c
	cc $(GMPCFLAGS) -o emirp emirp.c

palindromicprime:	palindromicprime.c
	cc $(CFLAGS) -o palindromicprime palindromicprime.c

palindromicprime2:	palindromicprime2.c
	cc $(CFLAGS) -o palindromicprime2 palindromicprime2.c

primegen:	primegen.c
	cc $(GMPCFLAGS) -o primegen primegen.c

primedigit:	primedigit.c
	cc $(CFLAGS) -o primedigit primedigit.c

primedigit2:	primedigit2.c
	cc $(GMPCFLAGS) -o primedigit2 primedigit2.c

mersenne:	mersenne.c
	cc $(GMPCFLAGS) -o mersenne mersenne.c

fermat:	fermat.c
	cc $(GMPCFLAGS) -o fermat fermat.c

twinprime:	twinprime.c
	cc $(CFLAGS) -o twinprime twinprime.c

twinprime2:	twinprime2.c
	cc $(CFLAGS) -o twinprime2 twinprime2.c

brotherprime:	brotherprime.c
	cc $(CFLAGS) -o brotherprime brotherprime.c

brotherprime2:	brotherprime2.c
	cc $(CFLAGS) -o brotherprime2 brotherprime2.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
