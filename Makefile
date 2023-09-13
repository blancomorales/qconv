# See LICENSE file for copyright and license details.
SRC = main.c qtob.c btoq.c qnum.c
OBJ = $(SRC:.c=.o)

CFLAGS = -std=c99 -O2 -Wall -pedantic -Wextra

qconv: $(OBJ)
	gcc -o $@ $^

$(OBJ): Makefile qnum.h

.c.o:
	gcc -c $(CFLAGS) $<

clean:
	rm -f $(OBJ) qconv
