SRC=src
openhack: bin
	make openhack -C $(SRC)
	cp $(SRC)/openhack bin/

bin:
	mkdir bin

clean:
	make clean -C $(SRC)
	rm bin/openhack
