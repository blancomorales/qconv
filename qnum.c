/* See LICENSE file for copyright and license details. */
#include "qnum.h"

static long gcd(long a, long b)
{
	while (b != 0) {
		a %= b;
		if (a == 0)
			return b;
		b %= a;
	}

	return a;
}

/* Reduce fraction n to lowest terms. */
void qnum_reduce(qnum *n)
{
	long d = gcd(n->num, n->den);

	n->num /= d;
	n->den /= d;
}
