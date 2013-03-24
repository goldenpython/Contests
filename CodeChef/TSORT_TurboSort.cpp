/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem Turbo Sort / TSORT                                               */



#include <stdio.h>

#define MAX		1000000


int g_arrnNumbers[MAX];


void qsort(int lo, int hi) {
	int i = lo, j = hi;
	int mid = g_arrnNumbers[(i + j) >> 1];

	while (i <= j) {
		while (g_arrnNumbers[i] < mid)
			i++;

		while (g_arrnNumbers[j] > mid)
			j--;

		if (i <= j) {
			int aux = g_arrnNumbers[i];
			g_arrnNumbers[i] = g_arrnNumbers[j];
			g_arrnNumbers[j] = aux;

			i++; j--;
		}
	}

	if (i < hi)
		qsort(i, hi);

	if (j > lo)
		qsort(lo, j);
}


int main() {
	int nN;

	scanf("%d", &nN);

	for (int nLoop = 0; nLoop < nN; nLoop++)
		scanf("%d", &g_arrnNumbers[nLoop]);

	qsort(0, nN - 1);

	for (int nLoop = 0; nLoop < nN; nLoop++)
		printf("%d\n", g_arrnNumbers[nLoop]);

	return 0;
}