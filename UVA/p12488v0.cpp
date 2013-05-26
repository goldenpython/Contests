/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12488 - Start Grid                                               */



#include <stdio.h>

int main() {
	const int MAX_DRIVERS = 32;

	int nN;

	while (scanf("%d", &nN) == 1) {
		int arrnStart[MAX_DRIVERS], arrnPos[MAX_DRIVERS];
		for (int nLoop = 0; nLoop < nN; nLoop++) {
			scanf("%d", &arrnStart[nLoop]);
			arrnPos[arrnStart[nLoop]] = nLoop;
		}

		int arrnGoal[MAX_DRIVERS];
		for (int nLoop = 0; nLoop < nN; nLoop++)
			scanf("%d", &arrnGoal[nLoop]);	

		int nSol = 0;
		for (int nLoop1 = 1; nLoop1 < nN; nLoop1++)
			for (int nLoop2 = nLoop1; nLoop2; nLoop2--)
				if (arrnPos[arrnGoal[nLoop2]] < arrnPos[arrnGoal[nLoop2 - 1]]) {
					int nTemp = arrnGoal[nLoop2]; 
					arrnGoal[nLoop2] = arrnGoal[nLoop2 - 1]; 
					arrnGoal[nLoop2 - 1] = nTemp;

					nSol++;
				} else {
					break;
				}

		printf("%d\n", nSol);
	}

	return 0;
}