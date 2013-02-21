/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 147 - Dollars                                                    */


#include <stdio.h>

#define MAX			(30005 / 5)

int main() {
	const int arrnValues[] = {5 / 5, 10 / 5, 20 / 5, 50 / 5, 100 / 5, 200 / 5, 500 / 5, 1000 / 5, 2000 / 5, 5000 / 5, 10000 / 5};
	int j;
	float fN;
	long long *p1, *p2, arrllSol[MAX];

	for (j = 0; j < MAX; j++)
		arrllSol[j] = 1;

	for (j = 1; j < sizeof(arrnValues) / sizeof(int); j++) {
		p1 = arrllSol;
		p2 = arrllSol + arrnValues[j];
		for ( ; p2 < arrllSol + MAX; p2++, p1++)
			*p2 += *p1;
	}

	while (scanf("%f", &fN) == 1 && fN >= 0.02)
		printf("%6.2lf%17lld\n", fN, arrllSol[(int) ((fN + 0.0001) * 100) / 5]);

	return 0;
}