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

clean:
	@make clean -C $(SRC)
	@make clean -C test
	rm bin/openhack
