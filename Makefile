override CFLAGS += -g -Wall

.PHONY: all
all: ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7 ex1-8 ex1-9 \
	ex1-10 ex1-11 ex1-12 ex1-13 ex1-14 ex1-15 ex1-16 ex1-17 ex1-18

ex1-16 ex1-17 ex1-18: kandr.o

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7 ex1-8 ex1-9 \
	ex1-10 ex1-11 ex1-12 ex1-13 ex1-14 ex1-15 ex1-16 ex1-17 ex1-18
