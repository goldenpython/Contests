/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1185 - Big Number                                                */



#include <stdio.h>
#include <math.h>

#define MAX_NUMBERS	10000002

double g_arrlfFactorials[MAX_NUMBERS];

int main() {
	int nNoCases, nN, nLoop, nLastComputedFactorial = 1;
	double lfFactorial;

	g_arrlfFactorials[0] = g_arrlfFactorials[1] = 0;

	for (scanf("%d", &nNoCases); nNoCases; nNoCases--) {
		scanf("%d", &nN);


		if (nLastComputedFactorial < nN) {
			for (nLoop = nLastComputedFactorial + 1; nLoop <= nN; nLoop++)
				g_arrlfFactorials[nLoop] += log(nLoop) + g_arrlfFactorials[nLoop - 1];

			nLastComputedFactorial = nN;
		}
		
		lfFactorial = g_arrlfFactorials[nN];
		lfFactorial /= log(10);

		printf("%d\n", (int)ceil(lfFactorial + 1E-10));
	}
	return 0;
}
