/* See LICENSE file for copyright and license details. */

typedef struct {
	long long num;
	long long den;
} qnum;

void qnum_reduce(qnum *n);
