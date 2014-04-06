/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12704 - Little Masters                                           */


#include <stdio.h>
#include <math.h>

int main() {
	int nNoTestCases;

	for (scanf("%d", &nNoTestCases); nNoTestCases--; ) {
		int nX, nY, nR;
		scanf("%d %d %d", &nX, &nY, &nR);

		float fDistToCenterSq = sqrt((double)(nX * nX + nY * nY));
		float fR = sqrt((double)(nR * nR));

		printf("%.2f %.2f\n", fR - fDistToCenterSq, fR + fDistToCenterSq);
	}

	return 0;
}