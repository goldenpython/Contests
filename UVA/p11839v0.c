/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>

int main() {
	int nN, nLoop, nA, nB, nC, nD, nE;
	int nSol, nGrayNumber;

	while (scanf("%d", &nN) && nN) {
		for (nLoop = 0; nLoop < nN; nLoop++) {
			scanf("%d %d %d %d %d", &nA, &nB, &nC, &nD, &nE);

			nGrayNumber = 0;

			if (nA <= 127)
				nGrayNumber++, nSol = 'A';

			if (nB <= 127)
				nGrayNumber++, nSol = 'B';

			if (nC <= 127)
				nGrayNumber++, nSol = 'C';

			if (nD <= 127)
				nGrayNumber++, nSol = 'D';

			if (nE <= 127)
				nGrayNumber++, nSol = 'E';

			if (nGrayNumber == 1)
				printf("%c\n", nSol);
			else
				printf("*\n");
		}
	}

	return 0;
}
