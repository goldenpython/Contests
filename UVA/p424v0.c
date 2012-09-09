/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 424 - Integer Inquiry                                            */


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH		128
#define MAX_NUMBERS_SIZE	220

int main() {
	char szLine[MAX_LINE_LENGTH];
	int i, j, MaxC, Sum, NumNumbers, Nrc[MAX_NUMBERS_SIZE], Nr[MAX_NUMBERS_SIZE][MAX_NUMBERS_SIZE];

	/* freopen("input/424.txt", "rt", stdin); */

	NumNumbers = 0;
	while (1) {
		gets(szLine);
		if (*szLine == '0' && *(szLine + 1) == '\0') {
			MaxC = 0;
			for (i = 0; i < NumNumbers; i++)
				if (Nrc[i] > MaxC)
					MaxC = Nrc[i];


			Sum = 0;
			for (j = 0; j < MaxC; j++) {
				for (i = 0; i < NumNumbers; i++) {
					Sum += Nr[i][j];
				}

				Nr[NumNumbers][j] = Sum % 10;
				Sum /= 10;
			}

			while (Sum) {
				Nr[NumNumbers][MaxC++] = Sum % 10;
				Sum /= 10;
			}

			for (i = MaxC - 1; i >= 0; i--)
				printf("%d", Nr[NumNumbers][i]);

			printf("\n");

			return 0;
		} else {
			j = Nrc[NumNumbers] = strlen(szLine);
			memset(Nr[NumNumbers], 0, sizeof(Nr[NumNumbers]));
			for (j-- ; j >= 0; j--)
				Nr[NumNumbers][Nrc[NumNumbers] - j - 1] = szLine[j] - '0';

			NumNumbers++;
		}
	}

	return 0;
}
