/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10323 - Factorial! You Must be Kidding!!!                        */



#include <stdio.h>

int main() {
	const long long kllMax = 6227020800ll;
	const long long kllMin = 10000ll;
	int nSize;
	long long arrllFactorials[32];
	
	arrllFactorials[0] = 1;
	for (int nLoop = 1; ; nLoop++) {
		arrllFactorials[nLoop] = arrllFactorials[nLoop - 1] * nLoop;
		if (arrllFactorials[nLoop] > kllMax) {
			nSize = nLoop;
			break;
		}
	}

	int nN;
	while (scanf("%d", &nN) == 1) {
		if (nN >= nSize || (nN < 0 && -nN % 2))
			printf("Overflow!\n");
		else if ((nN >= 0 && arrllFactorials[nN] < kllMin) || (nN < 0 && !(-nN % 2)))
			printf("Underflow!\n");
		else
			printf("%lld\n", arrllFactorials[nN]);
	}


	return 0;
}