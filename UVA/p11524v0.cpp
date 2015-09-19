/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11524 - InCircle                                    */


// https://en.wikipedia.org/wiki/Incircle_and_excircles_of_a_triangle#Other_incircle_properties

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int nN;
	for (cin >> nN; nN--; ) {
		double fR, fM1, fN1, fM2, fN2, fM3, fN3;
		cin >> fR >> fM1 >> fN1 >> fM2 >> fN2 >> fM3 >> fN3;

		double fX = fR * sqrt((fM1 * fM2 + fN1 * fM2 + fN2 * fN1) / (fM1 * fN1 * fN2 * fN1));
		fM1 *= fX; fN1 *= fX;

		double fY = fN1 / fM2;
		fM2 *= fY; fN2 *= fY;

		double fZ = fN2 / fM3;
		fM3 *= fZ; fN3 *= fZ;

		fM1 += fN1; fM2 += fN2; fM3 += fN3;
		double fP2 = (fM1 + fM2 + fM3) / 2;
		double fA = sqrt(fP2 * (fP2 - fM1) * (fP2 - fM2) * (fP2 - fM3));

		cout << fixed << setprecision(4) << fA << endl;
	}

	return 0;
}