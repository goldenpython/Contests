/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10633 - Rare Easy Problem                                        */



#include <stdio.h>

void PrintUnsignedLongLong(unsigned long long a) {
	static int cf[100], nrc;
	int i;

	nrc = 0;
	while (a) {
		cf[nrc++] = (int)(a % 10);
		a /= 10;
	}

	for (i = nrc - 1; i >= 0; i--)
		printf("%d", cf[i]);
}

int main() {
	unsigned long long k, a;
	int sum;
	char szLine[30], *p;

	while (gets(szLine)) {
		k = 0;
		sum = 0;
		for (p = szLine; *p; p++) {
			k = k * 10 + (unsigned long long)(*p - '0');
			sum += *p - '0';
		}

		if (!k)
			return 0;

		if (sum % 9) {
			a = (k * 10 - (sum % 9)) / 9;
			PrintUnsignedLongLong(a);
			printf("\n");
		} else {
			a = (k * 10 - 9) / 9;
			PrintUnsignedLongLong(a);
			printf(" ");

			a = (k * 10) / 9;
			PrintUnsignedLongLong(a);
			printf("\n");
		}
	}

	return 0;
}
