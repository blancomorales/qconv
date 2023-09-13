/* See LICENSE file for copyright and license details. */
#include <errno.h>
#include <limits.h>

#include "qnum.h"

static char buf[(sizeof(long) + 1) * 8];
static char *endc = buf + sizeof(buf) - 1;

static char itoc(register int i)
{
	if (0 <= i && i < 10)
		return i + '0';
	if (10 <= i && i < 36)
		return i + 'a' - 10;
	return '\0';
}

/* Convert fraction n to string in base b. */
const char *qtob(qnum n, int b)
{
	long ip;
	int neg = n.num < 0;
	char *s = buf, *t = endc;

	if (2 > b || b > 26) {
		errno = EINVAL;
		return (char *) 0;
	}

	if (neg)
		n.num = -n.num;

	ip = n.num / n.den;
	do {
		*--t = itoc(ip % b);
	} while ((ip /= b) > 0);
	if (neg)
		*--t = '-';

	while (t < endc)
		*s++ = *t++;

	if (n.den > 1) {
		*s++ = '.';
		n.num %= n.den;
		do {
			n.num = n.num * b;
			qnum_reduce(&n);
			*s++ = itoc((n.num / n.den) % b);
		} while (n.den > 1 && n.num < LONG_MAX / b && s < endc);
	}

	*s = '\0';

	return buf;
}
