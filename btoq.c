/* See LICENSE file for copyright and license details. */
#include "qnum.h"

static int ctoi(register char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';
	if ('a' <= c && c <= 'z')
		return c - 'a' + 10;
	return ((unsigned) ~0) >> 1;
}

/* Convert string s in base b to fraction. */
qnum btoq(const char *s, int b)
{
	int sign, dot;
	qnum n = {0, 1};

	while (*s == ' ' || *s == '\t')
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;

	for (dot = 0; *s != '\0'; ++s) {
		if (*s == '.' && !dot) {
			dot = 1;
			continue;
		}
		if (ctoi(*s) >= b)
			break;
		n.num = n.num * b + ctoi(*s);
		if (dot)
			n.den = n.den * b;
	}

	qnum_reduce(&n);
	n.num *= sign;

	return n;
}
