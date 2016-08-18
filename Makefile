.DEFAULT_GOAL := all

clean:
	rm -rf build bin lib

%$@:
	if [ ! -d "build" ]; then \
		./autogen.sh; \
	fi
	cd build && $(MAKE) $@
