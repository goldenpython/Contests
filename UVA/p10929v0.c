/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10929 - You can say 11                                           */



#include <stdio.h>

#define MAX 1005

#define ABS(a) ((a) > 0 ? (a) : -(a))

char number[MAX];



int main() {
	char *p;
	int sum;

	while (1) {
		gets(number);

		if (*number == '0' && !*(number + 1))
			return 0;

		sum = 0;
		for (p = number; *p; ) {
			if ((int)p & 0x1)
				sum += *p++;
			else
				sum -= *p++;
		}

		sum = ABS(sum);
		if ((p - number) & 0x1)
			sum -= '0';

		if (!(ABS(sum) % 11))
			printf("%s is a multiple of 11.\n", number);
		else
			printf("%s is not a multiple of 11.\n", number);
	}	

	return 0;
} 
