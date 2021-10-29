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
