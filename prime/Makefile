CFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= prime1 prime2 prime3 prime10trillions gmpprime1


all:	$(OUTS)

prime1:	prime1.c
	cc $(CFLAGS) -o prime1 prime1.c

prime2:	prime2.c
	cc $(CFLAGS) -o prime2 prime2.c

prime3:	prime3.c
	cc $(CFLAGS) -o prime3 prime3.c

prime10trillion:	prime10trillions.c
	cc $(CFLAGS) -o prime10trillions prime10trillions.c

gmpprime1:	gmpprime1.c
	cc $(CFLAGS) -o gmpprime1 gmpprime1.c

clean:
	rm -f $(OUTS)
