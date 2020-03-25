CFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall

OUTS	= emirp palindromicprime palindromicprime2 primegen primedigit primedigit2 mersenne fermat twinprime twinprime2 brotherprime brotherprime2


all:	$(OUTS)

emirp:	emirp.c
	cc $(CFLAGS) -o emirp emirp.c

palindromicprime:	palindromicprime.c
	cc $(CFLAGS) -o palindromicprime palindromicprime.c

palindromicprime2:	palindromicprime2.c
	cc $(CFLAGS) -o palindromicprime2 palindromicprime2.c

primegen:	primegen.c
	cc $(CFLAGS) -o primegen -lgmp primegen.c

primedigit:	primedigit.c
	cc $(CFLAGS) -o primedigit primedigit.c

primedigit2:	primedigit2.c
	cc $(CFLAGS) -o primedigit2 primedigit2.c

mersenne:	mersenne.c
	cc $(CFLAGS) -o mersenne -lgmp mersenne.c

fermat:	fermat.c
	cc $(CFLAGS) -o fermat -lgmp fermat.c

twinprime:	twinprime.c
	cc $(CFLAGS) -o twinprime twinprime.c

twinprime2:	twinprime2.c
	cc $(CFLAGS) -o twinprime2 twinprime2.c

brotherprime:	brotherprime.c
	cc $(CFLAGS) -o brotherprime brotherprime.c

brotherprime2:	brotherprime2.c
	cc $(CFLAGS) -o brotherprime2 brotherprime2.c

clean:
	rm -f $(OUTS)
