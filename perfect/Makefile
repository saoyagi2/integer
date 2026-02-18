CFLAGS = -O3 -Wall

GMPCFLAGS = -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= perfect perfectarray multiplyperfectarray

.PHONY: all clean test


all:	$(OUTS)

perfect:	perfect.c
	cc $(CFLAGS) -o perfect perfect.c

perfectarray:	perfectarray.c
	cc $(GMPCFLAGS) -o perfectarray perfectarray.c

multiplyperfectarray:	multiplyperfectarray.c
	cc $(GMPCFLAGS) -o multiplyperfectarray multiplyperfectarray.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
