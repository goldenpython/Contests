/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12578 - 10:6:2                                                   */



#include <stdio.h>

#define PI	3.1415926535897932

int main() {
	int nT, nL;
	double lfAreaRect, lfAreaCircle;

	for (scanf("%d", &nT); nT; nT--) {
		scanf("%d", &nL);

		lfAreaCircle = PI * nL * nL / 25.0;
		lfAreaRect = nL * nL * 6.0 / 10.0 - lfAreaCircle;

		printf("%.2lf %.2lf\n", lfAreaCircle, lfAreaRect);
	}

	return 0;
}
