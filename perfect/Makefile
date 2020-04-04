CFLAGS = -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp

OUTS	= perfect perfectarray gmpperfectarray multiplyperfect


all:	$(OUTS)

perfect:	perfect.c
	cc $(CFLAGS) -o perfect perfect.c

perfectarray:	perfectarray.c
	cc $(CFLAGS) -o perfectarray perfectarray.c

gmpperfectarray:	gmpperfectarray.c
	cc $(CFLAGS) -g3 -o gmpperfectarray gmpperfectarray.c

multiplyperfect:	multiplyperfect.c
	cc $(CFLAGS) -o multiplyperfect multiplyperfect.c

clean:
	rm -f $(OUTS)
