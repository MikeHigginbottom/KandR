override CFLAGS += -g -Wall
.PHONY: all
all: ex1-1

.PHONY: clean
clean:
	-rm -f *.o \
	ex1-1
