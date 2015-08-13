CFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall

OUTS	= collatz goldbach goldbach2 ogr ogr2 pythagoras


all:	$(OUTS)

collatz:	collatz.c
	cc $(CFLAGS) -o collatz -lgmp collatz.c

goldbach:	goldbach.c
	cc $(CFLAGS) -o goldbach goldbach.c

goldbach2:	goldbach2.c
	cc $(CFLAGS) -o goldbach2 -lgmp goldbach2.c

ogr:	ogr.c
	cc $(CFLAGS) -o ogr ogr.c

ogr2:	ogr2.c
	cc $(CFLAGS) -o ogr2 ogr2.c

pythagoras:	pythagoras.c
	cc $(CFLAGS) -o pythagoras pythagoras.c

clean:
	rm -f $(OUTS)
