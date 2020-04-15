CFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= collatz goldbach goldbach2 gmpgoldbach2 ogr ogr2 pythagoras


all:	$(OUTS)

collatz:	collatz.c
	cc $(CFLAGS) -o collatz collatz.c

goldbach:	goldbach.c
	cc $(CFLAGS) -o goldbach goldbach.c

goldbach2:	goldbach2.c
	cc $(CFLAGS) -o goldbach2 goldbach2.c

gmpgoldbach2:	gmpgoldbach2.c
	cc $(CFLAGS) -o gmpgoldbach2 gmpgoldbach2.c

ogr:	ogr.c
	cc $(CFLAGS) -o ogr ogr.c

ogr2:	ogr2.c
	cc $(CFLAGS) -o ogr2 ogr2.c

pythagoras:	pythagoras.c
	cc $(CFLAGS) -o pythagoras pythagoras.c

clean:
	rm -f $(OUTS)
