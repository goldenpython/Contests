/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11428 - Cubes                                                    */


#include <stdio.h>
#include <math.h>

#define MAX	60

int BinSearch(int *Cubes, int iLo, int iHi, int iN) {
	int i = iLo, j = iHi, m;

	while (i <= j) {
		m = (i + j) >> 1;

		if (Cubes[m] < iN)
			i = m + 1;
		else
			j = m - 1;
	}

	return i;
}

int main() {
	int N, i, index, x, max;
	double delta;
	int Cubes[MAX];

	for (i = 0; i < MAX; i++)
		Cubes[i] = i * i * i;

	while (scanf("%d", &N), N) {
		for (i = 0; Cubes[i] < N; i++);

		delta = sqrt(1 + 4 * 1 * (N - 1) / 3.0);
		max = (int)((1 + delta) / 2.0);

		for ( ; i <= max; i++) {
			x = Cubes[i] - N;
			index = BinSearch(Cubes, 1, max, x);
			if (Cubes[index] == x) {
				printf("%d %d\n", i, index);
				i = -1;
				break;
			}
		}

		if (i != -1)
			printf("No solution\n");
	}

	return 0;
}
