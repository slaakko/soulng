all:
	$(MAKE) -C soulng
	$(MAKE) -C examples
	$(MAKE) -C sngxml

clean:
	$(MAKE) -C soulng clean
	$(MAKE) -C examples clean
	$(MAKE) -C sngxml clean

install:
	$(MAKE) -C soulng install
	$(MAKE) -C examples install
	$(MAKE) -C sngxml install
