.PHONY: help clean localserve local-serve-with-output local-shell

# the following 3 lines are critical - do not alter or remove them!
# makes entire target/recipe execute within a single bash process.
.ONESHELL:
export SHELL := /bin/bash
export SHELLOPTS := $(if $(SHELLOPTS),$(SHELLOPTS):)errexit:pipefail

build:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	cmake --build .
execute-program:
	clear
	./build/myprogram
compile-run:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	cmake --build . --config build_type && \
	clear && \
	./myprogram teste
	
