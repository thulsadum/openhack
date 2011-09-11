SRC=src
openhack: bin compile
	@make openhack -C $(SRC)
	cp $(SRC)/openhack bin/

.PHONY : compile
compile:
	@make $@ -C src

content:
	make -C $(SRC)/content

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
