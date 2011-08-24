SRC=src
openhack:
	make openhack -C $(SRC)
	cp $(SRC)/openhack bin/

clean:
	make clean -C $(SRC)
	rm bin/openhack
