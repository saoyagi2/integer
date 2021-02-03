SUBDIRS = misc perfect prime primemisc yuuai

.PHONY: all clean test


all:
	@for subdir in $(SUBDIRS); do $(MAKE) -C $$subdir all; done

test:
	@for subdir in $(SUBDIRS); do $(MAKE) -C $$subdir test; done

clean:
	@for subdir in $(SUBDIRS); do $(MAKE) -C $$subdir clean; done
