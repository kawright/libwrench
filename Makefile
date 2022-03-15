# PHONY TARGETS

.PHONY: clean bins tests all

install: build/static/libwrench.a build/shared/libwrench.so wrench.h
	@ echo -n INSTALLING...
	@ mkdir -p /usr/local/lib/
	@ cp build/static/libwrench.a /usr/local/lib/libwrench.a
	@ chmod 644 /usr/local/lib/libwrench.a
	@ cp build/shared/libwrench.so /usr/local/lib/libwrench.so
	@ chmod 644 /usr/local/lib/libwrench.so
	@ mkdir -p /usr/local/include/
	@ cp wrench.h /usr/local/include/wrench.h
	@ chmod 644 /usr/local/include/wrench.h
	@ mkdir -p /usr/local/share
	@ mkdir -p /usr/local/share/man
	@ mkdir -p /usr/local/share/man/man3
	@ gzip -c wrench.TROFF > /usr/local/share/man/man3/wrench.3.gz
	@ mandb > /dev/null
	@ echo DONE!

uninstall:
	@ echo -n UNINSTALLING...
	@ rm -f /usr/local/lib/libwrench.a
	@ rm -f /usr/local/lib/libwrench.so
	@ rm -f /usr/local/include/wrench.h
	@ rm -f /usr/local/share/man/man3/wrench.1.gz
	@ echo DONE!

bins: build/static/libwrench.a build/shared/libwrench.so
	@ echo ALL BINARIES HAVE BEEN COMPILED!

tests: build/tests/test_wrench
	@ echo ALL TEST SUITES HAVE BEEN COMPILED!

# UNIT TEST OBJECT FILES

testobjs = build/tests/obj/wrench.o \
	build/tests/obj/test_wrench.o \
	build/tests/obj/test_ASSERTEQ.o \
	build/tests/obj/test_ASSERTFALSE.o \
	build/tests/obj/test_ASSERTGT.o \
	build/tests/obj/test_ASSERTGTEQ.o \
	build/tests/obj/test_ASSERTLT.o \
	build/tests/obj/test_ASSERTLTEQ.o \
	build/tests/obj/test_ASSERTNEQ.o \
	build/tests/obj/test_ASSERTNOTNULL.o \
	build/tests/obj/test_ASSERTNULL.o \
	build/tests/obj/test_ASSERTSTREQ.o \
	build/tests/obj/test_ASSERTSTRGT.o \
	build/tests/obj/test_ASSERTSTRGTEQ.o \
	build/tests/obj/test_ASSERTSTRLT.o

# TESTS

build/tests/test_wrench: $(testobjs)
	@ echo -n COMPILING build/tests/test_wrench...
	@ gcc -g -Wall -o build/tests/test_wrench $(testobjs)
	@ echo DONE!

build/tests/obj/wrench.o: wrench.c
	@ echo -n BUILDING build/tests/obj/wrench.o...
	@ mkdir -p build
	@ mkdir -p build/tests
	@ mkdir -p build/tests/obj
	@ gcc -g -Wall -o build/tests/obj/wrench.o -c wrench.c
	@ echo DONE!

build/tests/obj/%.o: tests/%.c
	@ echo -n BUILDING $@...
	@ mkdir -p build
	@ mkdir -p build/tests
	@ mkdir -p build/tests/obj
	@ gcc -g -Wall -o $@ -c $<
	@ echo DONE!

# BINS

build/static/libwrench.a: build/static/wrench.o
	@ echo -n COMPILING build/static/libwrench.a...
	@ ar -cvq build/static/libwrench.a build/static/wrench.o > /dev/null
	@ echo DONE!

build/shared/libwrench.so: build/shared/wrench.o
	@ echo -n COMPILING build/static/libwrench.so...
	@ gcc -shared -o build/shared/libwrench.so build/shared/wrench.o
	@ echo DONE!

build/static/wrench.o: wrench.c wrench.h
	@ echo -n BUILDING build/static/wrench.o...
	@ mkdir -p build
	@ mkdir -p build/static
	@ gcc -g -Wall -o build/static/wrench.o -c wrench.c
	@ echo DONE!

build/shared/wrench.o: wrench.c wrench.h
	@ echo -n BUILDING build/shared/wrench.o...
	@ mkdir -p build
	@ mkdir -p build/shared
	@ gcc -g -Wall -fpic -o build/shared/wrench.o -c wrench.c
	@ echo DONE!

# CLEANUP

clean:
	@ echo -n CLEANING BUILD DIRECTORY...
	@ rm -R -f build
	@ echo DONE!