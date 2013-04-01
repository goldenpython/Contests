/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const char *keys[] = {
		"`1234567890-=",
		"qwertyuiop[]",
		"asdfghjkl;'",
		"zxcvbnm,./\\"
	};

	int i;
	const char *p;
	char kmap[255], szLine[255];

	memset(kmap, 0, sizeof(kmap));

	for (i = 0; i < sizeof(keys) / sizeof(char *); i++) {
		for (p = keys[i] + 2; *p; p++) {
			kmap[*p] = *(p - 2);
			kmap[toupper(*p)] = *(p - 2);
		}
	}

	while (gets(szLine)) {
		for (p = szLine; *p; p++)
			if (kmap[*p])
				*p = kmap[*p];

		printf("%s\n", szLine);
	}


	return 0;
}
