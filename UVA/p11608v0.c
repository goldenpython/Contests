/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11608 - Problem D No Problem                                     */



#include <stdio.h>

int main() {
	int nFirst, nLoop, nCaseLoop = 1;
	int arrnProduced[12];
	int arrnRequired[12];

	while (scanf("%d", &nFirst) && nFirst >= 0) {
		for (nLoop = 0; nLoop < 12; nLoop++)
			scanf("%d", &arrnProduced[nLoop]);

		for (nLoop = 0; nLoop < 12; nLoop++)
			scanf("%d", &arrnRequired[nLoop]);

		printf("Case %d:\n", nCaseLoop);
		for (nLoop = 0; nLoop < 12; nLoop++) {
			if (nFirst >= arrnRequired[nLoop]) {
				nFirst -= arrnRequired[nLoop];
				printf("No problem! :D\n");
			} else {
				printf("No problem. :(\n");
			}

			nFirst += arrnProduced[nLoop];
		}

		nCaseLoop++;
	}

	return 0;
}
