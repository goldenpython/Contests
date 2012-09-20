/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 357 - Let Me Count The Ways                                      */


#include <stdio.h>

#define MAX			30001

int main() {
	const int arrnValues[] = {1, 5, 10, 25, 50};
	int nN, j;
	long long *p1, *p2, arrllSol[MAX];

	for (j = 0; j < MAX; j++)
		arrllSol[j] = 1;

	for (j = 1; j < sizeof(arrnValues) / sizeof(int); j++) {
		p1 = arrllSol;
		p2 = arrllSol + arrnValues[j];
		for ( ; p2 < arrllSol + MAX; p2++, p1++)
			*p2 += *p1;
	}

	while (scanf("%d", &nN) == 1) {
		if (arrllSol[nN] > 1)
			printf("There are %lld ways to produce %d cents change.\n", arrllSol[nN], nN);
		else
			printf("There is only 1 way to produce %d cents change.\n", nN);
	}

	return 0;
}
