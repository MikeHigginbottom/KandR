override CFLAGS += -g -Wall
.PHONY: all
all: ex1-1 ex1-2 ex1-3

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1 ex1-2 ex1-3
