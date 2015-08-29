override CFLAGS += -g -Wall

.PHONY: all
all: ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1 ex1-2 ex1-3 ex1-4 ex1-5 ex1-6 ex1-7
