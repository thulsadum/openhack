export MAKE_QUIET=1

.PHONY : all
all: test openhack

.PHONY : openhack
openhack: bin compile content
	@make openhack -C src
	cp src/core/openhack bin/

.PHONY : compile content
compile content:
	@make $@ -C src

bin:
	mkdir bin

.PHONY : doc
doc: Doxyfile src/core/*.c include/*.h
	doxygen

.PHONY : test
test: compile
	@make test -C test

.PHONY : clean-all
clean-all: clean-src clean-test clean-bin clean-doc

.PHONY : clean-doc
clean-doc:
	-rm -r doc/html

.PHONY : clean
clean: clean-src clean-bin

.PHONY : clean-src
clean-src:
	@make clean -C src
clean-bin:
	-rm bin/openhack
	-rm -r bin

.PHONY : clean-test
clean-test:
	@make clean -C test

.PHONY : help
help:
	@echo "List of targets:"
	@echo "all		makes everything: compile content test openhack"
	@echo "openhack*	makes the executeable (implicites: compile content)"
	@echo "compile*		compiles the core source code"
	@echo "content*		compiles the game content"
	@echo "doc		makes the documentation	(requires doxygen)"
	@echo "test*		build and run tests"
	@echo "clean-all	cleans everything: clean-src clean-test"
	@echo "clean-src	cleans the source directory"
	@echo "clean-bin	removes the executeable and the bin directory"
	@echo "clean-test	cleans the tests"
	@echo "help		gues what. :)"
	@echo 
	@echo "* is made by default target (all)"
