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