/* See LICENSE file for copyright and license details. */
#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "qnum.h"

extern qnum btoq(const char *str, int base);
extern const char *qtob(qnum nmb, int base);

/* Convert number from any base to another base. */
int main(int argc, char **argv)
{
	qnum n;
	const char *s = argv[1];

	if (argc != 4) {
		fprintf(stderr, "Usage: %s number base base\n", argv[0]);
		exit(1);
	}

	n = btoq(s, atoi(argv[2]));
	if (errno)
		err(errno, NULL);

	s = qtob(n, atoi(argv[3]));
	if (errno)
		err(errno, NULL);

	puts(s);
	exit(0);
}
