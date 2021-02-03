CFLAGS	= -O3 -Wall

OUTS	= konyaku konyaku2 syakou syakou2 yuuai yuuai2

.PHONY: all clean test


all:	$(OUTS)

konyaku:	konyaku.c
	cc $(CFLAGS) -o konyaku konyaku.c

konyaku2:	konyaku2.c
	cc $(CFLAGS) -o konyaku2 konyaku2.c

syakou:	syakou.c
	cc $(CFLAGS) -o syakou syakou.c

syakou2:	syakou2.c
	cc $(CFLAGS) -o syakou2 syakou2.c

yuuai:	yuuai.c
	cc $(CFLAGS) -o yuuai yuuai.c

yuuai2:	yuuai2.c
	cc $(CFLAGS) -o yuuai2 yuuai2.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
