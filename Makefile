.DEFAULT_GOAL := all
clean:
	rm -rf build

%$@:
	if [ ! -d "build" ]; then \
		./autogen.sh; \
	fi
	cd build && $(MAKE) $@
