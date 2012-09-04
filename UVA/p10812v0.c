/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10812 - Beat the Spread!                                         */



#include <stdio.h>

int main() {
	int nrcases, s, d, a, b;

	for (scanf("%d", &nrcases); nrcases; nrcases--) {
		scanf("%d %d", &s, &d);
		
		if ((s + d) & 0x1)
			printf("impossible\n");
		else {
			a = (s + d) / 2;
			b = s - a;

			if (a < 0 || b < 0)
				printf("impossible\n");
			else
				printf("%d %d\n", a, b);
		}
	}

	return 0;
}
