override CFLAGS += -g -Wall
.PHONY: all
all: ex1-1 ex1-2

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1 ex1-2
