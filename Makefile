all:
	mkdir -p bin
	mkdir -p lib
	$(MAKE) -C soulng
	$(MAKE) -C examples
	$(MAKE) -C sngxml
	$(MAKE) -C sngcpp
	$(MAKE) -C sngcm

clean:
	$(MAKE) -C soulng clean
	$(MAKE) -C examples clean
	$(MAKE) -C sngxml clean
	$(MAKE) -C sngcpp clean
	$(MAKE) -C sngcm clean

install:
	$(MAKE) -C soulng install
	$(MAKE) -C examples install
	$(MAKE) -C sngxml install
	$(MAKE) -C sngcpp install
	$(MAKE) -C sngcm install

SRCDIR = ~/soulng-3.1.0-src
SRCDIRNAME = soulng-3.1.0-src
SRCPACKAGE = soulng-3.1.0-src.tar.bz2

srcpackage:
	mkdir -p $(SRCDIR)
	cd ~/soulng && git archive master | tar -x -C $(SRCDIR)
	cp /mnt/c/work/soulng/unicode/soulng_ucd.bin $(SRCDIR)/unicode
	cd ~ && tar cjf $(SRCPACKAGE) $(SRCDIRNAME)
