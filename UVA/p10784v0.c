/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10784 - Diagonal                                                 */


#include <stdio.h>
#include <math.h>

int main() {
	double n, delta;
	int nrcase;

	nrcase = 1;
	while (scanf("%lf", &n) == 1, (int)n) {

		delta = 9.0 + 8.0 * n;
		n = (3.0 + sqrt(delta)) / 2.0;
		n = ceil(n);

		printf("Case %d: %d\n", nrcase, (int)n);

		nrcase++;
	}
}
