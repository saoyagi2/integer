CFLAGS	= -O3 -Wall

OUTS	= konyaku syakou yuuai


all:	$(OUTS)

test:
	@./test.sh

konyaku:	konyaku.c
	cc $(CFLAGS) -o konyaku konyaku.c

syakou:	syakou.c
	cc $(CFLAGS) -o syakou syakou.c

yuuai:	yuuai.c
	cc $(CFLAGS) -o yuuai yuuai.c

clean:
	rm -f $(OUTS)
