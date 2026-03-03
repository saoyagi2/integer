CFLAGS	= -O3 -Wall

GMPCFLAGS	= -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= prime1 prime2 prime3

.PHONY: all clean test


all:	$(OUTS)

prime1:	prime1.c
	cc $(CFLAGS) -o prime1 prime1.c

prime2:	prime2.c
	cc $(CFLAGS) -o prime2 prime2.c

prime3:	prime3.c
	cc $(CFLAGS) -o prime3 prime3.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
