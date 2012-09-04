/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10921 - Find the Telephone                                       */



#include <stdio.h>
#include <string.h>

#define MAX_LEN 40

int coresp[256];


void Init() {
	int i;

	for (i = '0'; i <= '9'; i++)
		coresp[i] = i;

	for (i = 'A'; i <= 'C'; i++)
		coresp[i] = '2';

	for (i = 'D'; i <= 'F'; i++)
		coresp[i] = '3';

	for (i = 'G'; i <= 'I'; i++)
		coresp[i] = '4';

	for (i = 'J'; i <= 'L'; i++)
		coresp[i] = '5';

	for (i = 'M'; i <= 'O'; i++)
		coresp[i] = '6';

	for (i = 'P'; i <= 'S'; i++)
		coresp[i] = '7';

	for (i = 'T'; i <= 'V'; i++)
		coresp[i] = '8';

	for (i = 'W'; i <= 'Z'; i++)
		coresp[i] = '9';

	coresp['-'] = '-';
}

int main() {
	char line[MAX_LEN], *p;

	Init();	

	while (gets(line)) {
		for (p = line; *p; p++)
			*p = coresp[*p];

		printf("%s\n", line);
	}
}
