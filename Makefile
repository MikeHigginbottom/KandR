suites = ex1-20_tests.o ex1-21_tests.o kandr.o debug.o

override CFLAGS += -g -Wall

.PHONY: all
all: $(suites) ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7 ex1-8 ex1-9 \
	ex1-10 ex1-11 ex1-12 ex1-13 ex1-14 ex1-15 ex1-16 ex1-17 ex1-18 ex1-19
	cc -o ex1-20_tests ex1-20_tests.o kandr.o debug.o
	cc -o ex1-21_tests ex1-21_tests.o kandr.o debug.o
	sh ./test_harness.sh


ex1-16 ex1-17 ex1-18 ex1-19: kandr.o

$(suites): kandr.h test_framework.h debug.h

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7 ex1-8 ex1-9 \
	ex1-10 ex1-11 ex1-12 ex1-13 ex1-14 ex1-15 ex1-16 ex1-17 ex1-18 ex1-19 \
	ex1-20_tests ex1-21_tests
