SRC=src

export MAKE_QUIET=1

bin/openhack: bin compile
	@make openhack -C $(SRC)
	cp $(SRC)/openhack bin/

.PHONY : compile
compile:
	@make $@ -C src

bin:
	mkdir bin

doc: Doxyfile src/*.c include/*.h
	doxygen

.PHONY : test
test: compile
	@make test -C test

.PHONY : ckean-all
clean-all: clean-src clean-test

.PHONY : clean
clean: clean-src

.PHONY : clean-src
clean-src:
	@make clean -C $(SRC)
	-rm bin/openhack

.PHONY : clean-test
clean-test:
	@make clean -C test
