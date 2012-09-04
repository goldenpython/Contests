/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10945 - Mother bear                                              */


#include <stdio.h>
#include <string.h>

#define MAX 10000

char s1[MAX], s2[MAX];
char *p1, *p2, sol;

int main() {
	while (gets(s1), strcmp(s1, "DONE")) {
		for (p1 = s1, p2 = s2; *p1; p1++) {
			*p1 = toupper(*p1);
			if (*p1 <= 'Z' && *p1 >= 'A')
				*p2++ = *p1;
		}
		*p2 = '\0';
		sol = 1;
		for (p1 = s2, p2 = s2 + strlen(s2) - 1; p1 <= p2; p1++, p2--)
			if (*p1 != *p2) {
				sol = 0;
				break;
			}

		if (sol)
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");
			
	}
}
