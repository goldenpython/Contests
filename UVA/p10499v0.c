/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10499 - The Land of Justice                                      */


#include <stdio.h>

int main() {
	int nN;
	long long int llnSol;

	while (scanf("%d", &nN), nN >= 0) {
		if (nN == 1) {
			printf("0%%\n");
		} else {
			llnSol = 100LL * nN / 4;
			printf("%lld%%\n", llnSol);
		}
	}

	return 0;
}
