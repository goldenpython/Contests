/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10940 - Throwing cards away II                                   */


#include <stdio.h>
#include <math.h>

int main() {
	int n, l, s;
	while (scanf("%d", &n), n) {
		l = log(n) / log(2.0);
		s = (n - (1 << l)) * 2;
		printf("%d\n", !s ? n : s);
	}
}
