CFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= collatz collatz2 goldbach ogr ogr2 pythagoras

.PHONY: all clean test


all:	$(OUTS)

collatz:	collatz.c
	cc $(CFLAGS) -o collatz collatz.c

collatz2:	collatz2.c
	cc $(CFLAGS) -o collatz2 collatz2.c

goldbach:	goldbach.c
	cc $(CFLAGS) -o goldbach goldbach.c

ogr:	ogr.c
	cc $(CFLAGS) -o ogr ogr.c

ogr2:	ogr2.c
	cc $(CFLAGS) -o ogr2 ogr2.c

pythagoras:	pythagoras.c
	cc $(CFLAGS) -o pythagoras pythagoras.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
