.PHONY: clean bins tests

bins: build/static/libwrench.a build/shared/libwrench.so

tests: build/tests/test_wrench

################################## T E S T S ###################################

build/tests/test_wrench: wrench.c wrench.h tests/test_wrench.c tests/test_wrench.h tests/test_ASSERTEQ.c tests/test_ASSERTFALSE.c tests/test_ASSERTGT.c
	@ echo ========================================
	@ echo Compiling test suite
	@ echo ========================================
	@ mkdir -p build
	@ mkdir -p build/tests
	@ mkdir -p build/tests/obj
	gcc -g -Wall -o build/tests/obj/wrench.o -c wrench.c
	gcc -g -Wall -o build/tests/obj/test_wrench.o -c tests/test_wrench.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTEQ.o -c tests/test_ASSERTEQ.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTFALSE.o -c tests/test_ASSERTFALSE.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTGT.o -c tests/test_ASSERTGT.c
	gcc -o build/tests/test_wrench build/tests/obj/wrench.o build/tests/obj/test_wrench.o build/tests/obj/test_ASSERTEQ.o build/tests/obj/test_ASSERTFALSE.o build/tests/obj/test_ASSERTGT.o
	@ echo Finished!

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