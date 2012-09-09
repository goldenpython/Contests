/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 443 - Knight Moves                                               */


#include <stdio.h>
#include <math.h>

#define MAX		5900
#define MAX_N	2000000000

int nr;
int numbers[MAX];


void qsort(int lo, int hi) {
	int i = lo, j = hi;
	int mid = numbers[(i + j) >> 1];

	while (i <= j) {
		while (numbers[i] < mid)
			i++;

		while (numbers[j] > mid)
			j--;

		if (i <= j) {
			int aux = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = aux;

			i++; j--;
		}
	}

	if (i < hi)
		qsort(i, hi);

	if (j > lo)
		qsort(lo, j);
}

void Generate() {
	int i2, i3, i5, i7;
	long long p, p2, p3, p5, p7;
	int lim3, lim5, lim7;
	
	nr = 0;

	for (i2 = 0, p2 = 1; p2 <= MAX_N; i2++, p2 *= 2) {
		lim3 = MAX_N / p2;
		for (i3 = 0, p3 = 1; p3 <= lim3; i3++, p3 *= 3) {
			lim5 = MAX_N / p2 / p3;
			for (i5 = 0, p5 = 1; p5 <= lim5; i5++, p5 *= 5) {
				lim7 = MAX_N / p2 / p3 / p5;
				for (i7 = 0, p7 = 1; p7 <= lim7; i7++, p7 *= 7) {
					numbers[nr++] = p2 * p3 * p5 * p7;
				}
			}
		}
	}

	qsort(0, nr - 1);
}

int main() {
	int n;
	char *term;

	Generate();

	while (scanf("%d", &n), n) {
		if ((n % 100 - n % 10) == 10)
			term = "th";
		else {
			switch (n % 10) {
				case 1:
					term = "st";
					break;

				case 2:
					term = "nd";
					break;

				case 3:
					term = "rd";
					break;

				default:
					term = "th";
					break;
			}
		}

		printf("The %d%s humble number is %d.\n", n, term, numbers[n - 1]);
	}

	return 0;
}
