all:
	$(MAKE) -C soulng
	$(MAKE) -C examples

clean:
	$(MAKE) -C soulng clean
	$(MAKE) -C examples clean

install:
	$(MAKE) -C soulng install
	$(MAKE) -C examples install
