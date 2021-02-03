CFLAGS = -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= perfect perfectarray gmpperfectarray multiplyperfectarray gmpmultiplyperfectarray

.PHONY: all clean test


all:	$(OUTS)

perfect:	perfect.c
	cc $(CFLAGS) -o perfect perfect.c

perfectarray:	perfectarray.c
	cc $(CFLAGS) -o perfectarray perfectarray.c

gmpperfectarray:	gmpperfectarray.c
	cc $(CFLAGS) -o gmpperfectarray gmpperfectarray.c

multiplyperfectarray:	multiplyperfectarray.c
	cc $(CFLAGS) -o multiplyperfectarray multiplyperfectarray.c

gmpmultiplyperfectarray:	gmpmultiplyperfectarray.c
	cc $(CFLAGS) -o gmpmultiplyperfectarray gmpmultiplyperfectarray.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
