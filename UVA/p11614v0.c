/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
	int nCaseLoop;
	long long nN;
	double dDelta, dSol;

	for (scanf("%d", &nCaseLoop); nCaseLoop--; ) {
		scanf("%lld", &nN);
		dDelta = 1.0 + 4.0 * 1.0 * 2.0 * (double)nN;
		dSol = (-1 + sqrt(dDelta)) / 2;

		printf("%d\n", (int)(dSol + 1E-10));
	}

	return 0;
}
