/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 661 - Blowing Fuses                                              */


#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES		20

int main() {
	int nN, nM, nC, nMaxConsumption, nConsumption, nLoop, nDevice, nCaseNumber = 1;
	int arrnDeviceConsumption[MAX_DEVICES];
	int arrnDeviceState[MAX_DEVICES];

	while (scanf("%d %d %d", &nN, &nM, &nC), nN || nM || nC) {

		for (nLoop = 0; nLoop < nN; nLoop++) {
			scanf("%d", &arrnDeviceConsumption[nLoop]);
			arrnDeviceState[nLoop] = 0;
		}

		nMaxConsumption = nConsumption = 0;
		for (nLoop = 0; nLoop < nM; nLoop++) {
			scanf("%d", &nDevice);
			nDevice--;

			if (arrnDeviceState[nDevice]) {
				nConsumption -= arrnDeviceConsumption[nDevice];
				arrnDeviceState[nDevice] = 0;
			} else {
				nConsumption += arrnDeviceConsumption[nDevice];
				arrnDeviceState[nDevice] = 1;
				if (nConsumption > nMaxConsumption)
					nMaxConsumption = nConsumption;
			}
		}

		printf("Sequence %d\n", nCaseNumber);
		if (nMaxConsumption > nC)
			printf("Fuse was blown.\n\n");
		else
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", nMaxConsumption);

		nCaseNumber++;
	}

	return 0;
}
