.PHONY : content openhack compile clean-core clean-content clean clean-src

openhack compile clean-core:
	@make $@ -C core
	
content clean-content:
	@make $@ -C content


clean clean-src: clean-content clean-core
