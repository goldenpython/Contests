/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>
#include <math.h>

#define PI		3.14159265358979323846

int main() {
	int nL, nW, nH, nAlpha;
	double dX, dAngle, dSol, dY, dTan, dTanRect;

	while (scanf("%d %d %d %d", &nL, &nW, &nH, &nAlpha) == 4) {
		dAngle = nAlpha * PI / 180;
		dTan = sin(dAngle) / cos(dAngle);
		dTanRect = (double)nH / nL;

		if (dTan <= dTanRect) {
			dX = nL * dTan;
			dSol = nL * nW * nH - dX * nL * nW / 2;
		} else {
			dY = nH / dTan;
			dSol = nH * dY * nW / 2;
		}

		printf("%.3lf mL\n", dSol);
	}

	return 0;
}
