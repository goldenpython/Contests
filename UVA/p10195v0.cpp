/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10195 - The Knights Of The Round Table                           */




#include <stdio.h>
#include <math.h>

int main() {
	double fA, fB, fC;

	while (scanf("%lf %lf %lf", &fA, &fB, &fC) == 3) {
		double fS = (fA + fB + fC) / 2;
		double fR = fS <= 0 ? 0.0 : sqrt((fS - fA) * (fS - fB) * (fS - fC) / fS);

		printf("The radius of the round table is: %.3lf\n", fR);
	}

	return 0;
}