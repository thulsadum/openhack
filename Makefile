SRC=src
openhack: bin
	make openhack -C $(SRC)
	cp $(SRC)/openhack bin/

bin:
	mkdir bin

doc: Doxyfile src/*.c include/*.h
	doxygen

clean:
	make clean -C $(SRC)
	rm bin/openhack
