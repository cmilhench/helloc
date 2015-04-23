PREFIX ?= /usr/local
SRC = src/main.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g -D_GNU_SOURCE -std=c99 -I deps/

helloc: $(OBJ)
	$(CC) $(OBJ) -o build/$@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) -c -o $@

install: mon
	cp -f mon $(PREFIX)/bin/helloc

uninstall:
	rm -f $(PREFIX)/bin/helloc

clean:
	rm -f build/helloc $(OBJ)

.PHONY: clean install uninstall
