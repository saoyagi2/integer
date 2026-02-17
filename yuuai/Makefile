CFLAGS	= -O3 -Wall

OUTS	= konyaku konyakuarray syakou syakouarray yuuai yuuaiarray

.PHONY: all clean test


all:	$(OUTS)

konyaku:	konyaku.c
	cc $(CFLAGS) -o konyaku konyaku.c

konyakuarray:	konyakuarray.c
	cc $(CFLAGS) -o konyakuarray konyakuarray.c

syakou:	syakou.c
	cc $(CFLAGS) -o syakou syakou.c

syakouarray:	syakouarray.c
	cc $(CFLAGS) -o syakouarray syakouarray.c

yuuai:	yuuai.c
	cc $(CFLAGS) -o yuuai yuuai.c

yuuaiarray:	yuuaiarray.c
	cc $(CFLAGS) -o yuuaiarray yuuaiarray.c

test:
	@./test.sh

clean:
	rm -f $(OUTS)
