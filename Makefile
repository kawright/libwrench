.PHONY: clean bins tests

bins: build/static/libwrench.a build/shared/libwrench.so

tests: build/tests/test_wrench

################################## T E S T S ###################################

build/tests/test_wrench: wrench.c wrench.h tests/test_wrench.c tests/test_wrench.h tests/test_ASSERTEQ.c tests/test_ASSERTFALSE.c tests/test_ASSERTGT.c tests/test_ASSERTGTEQ.c tests/test_ASSERTLT.c tests/test_ASSERTLTEQ.c tests/test_ASSERTNEQ.c tests/test_ASSERTNOTNULL.c tests/test_ASSERTNULL.c
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
	gcc -g -Wall -o build/tests/obj/test_ASSERTGTEQ.o -c tests/test_ASSERTGTEQ.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTLT.o -c tests/test_ASSERTLT.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTLTEQ.o -c tests/test_ASSERTLTEQ.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTNEQ.o -c tests/test_ASSERTNEQ.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTNOTNULL.o -c tests/test_ASSERTNOTNULL.c
	gcc -g -Wall -o build/tests/obj/test_ASSERTNULL.o -c tests/test_ASSERTNULL.c
	gcc -o build/tests/test_wrench build/tests/obj/wrench.o build/tests/obj/test_wrench.o build/tests/obj/test_ASSERTEQ.o build/tests/obj/test_ASSERTFALSE.o build/tests/obj/test_ASSERTGT.o build/tests/obj/test_ASSERTGTEQ.o build/tests/obj/test_ASSERTLT.o build/tests/obj/test_ASSERTLTEQ.o build/tests/obj/test_ASSERTNEQ.o build/tests/obj/test_ASSERTNOTNULL.o build/tests/obj/test_ASSERTNULL.o
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