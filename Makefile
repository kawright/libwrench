.PHONY: clean all

all: build/static/libwrench.a build/shared/libwrench.so

########################## L I B R A R Y    F I L E S ##########################

build/static/libwrench.a: build/static/wrench.o
	@ echo ========================================
	@ echo Compiling static library
	@ echo ========================================
	ar -cvq build/static/libwrench.a build/static/wrench.o
	@ echo Finished!

build/shared/libwrench.so: build/shared/wrench.o
	@ echo ========================================
	@ echo Compiling shared library
	@ echo ========================================
	gcc -shared -o build/shared/libwrench.so build/shared/wrench.o
	@ echo Finished!

########################### O B J E C T    F I L E S ###########################

build/static/wrench.o: wrench.c wrench.h
	@ echo ========================================
	@ echo Building static object files
	@ echo ========================================
	@ mkdir -p build
	@ mkdir -p build/static
	gcc -g -Wall -o build/static/wrench.o -c wrench.c
	@ echo Finished!

build/shared/wrench.o: wrench.c wrench.h
	@ echo ========================================
	@ echo Building shared object files
	@ echo ========================================
	@ mkdir -p build
	@ mkdir -p build/shared
	gcc -g -Wall -fpic -o build/shared/wrench.o -c wrench.c
	@ echo Finished!

################################## C L E A N ###################################

clean:
	@ echo ========================================
	@ echo Cleaning build directory
	@ echo ========================================
	@ rm -R build
	@ echo Finished!