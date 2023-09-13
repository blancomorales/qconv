#include <stdio.h>
#include <stdlib.h>

#include "qnum.h"

extern qnum btoq(const char *str, int base);
extern const char *qtob(qnum nmb, int base);

int main(int argc, char **argv)
{
	qnum n;
	const char *s = argv[1];

	if (argc != 4) {
		fprintf(stderr, "Usage: %s number base base\n", argv[0]);
		exit(1);
	}

	n = btoq(s, atoi(argv[2]));
	s = qtob(n, atoi(argv[3]));

	puts(s);
	exit(0);
}
