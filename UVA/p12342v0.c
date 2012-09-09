/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12342 - Tax Calculator                                           */



#include <stdio.h>
#include <math.h>

int main() {
	int nNoCases, nCaseLoop;
	double lfValue, lfTax;

	for (scanf("%d", &nNoCases), nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		scanf("%lf", &lfValue);

		do {
			lfTax = 0.0;
			if (lfValue >= 180000) {
				lfValue -= 180000;
			} else {
				lfValue = 0;
				break;
			}
			
			if (lfValue >= 300000) {
				lfValue -= 300000;
				lfTax += 300000 * 0.10;
			} else {
				lfTax += lfValue * 0.10;
				lfValue = 0;
				break;
			}

			if (lfValue >= 400000) {
				lfValue -= 400000;
				lfTax += 400000 * 0.15;
			} else {
				lfTax += lfValue * 0.15;
				lfValue = 0;
				break;
			}

			if (lfValue >= 300000) {
				lfValue -= 300000;
				lfTax += 300000 * 0.20;
			} else {
				lfTax += lfValue * 0.20;
				lfValue = 0;
				break;
			}

			lfTax += lfValue * 0.25;
		} while (0);

		if (lfTax > 0 && lfTax < 2000)
			lfTax = 2000;

		printf("Case %d: %d\n", nCaseLoop, (int)ceil(lfTax));
	}

	return 0;
}
