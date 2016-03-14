/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10773 - Back to Intermediate Math                                */


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		double fD, fV, fU;
		cin >> fD >> fV >> fU;
		if (fV < fU && fV > 0 && fU > 0)
			cout << "Case " << nCaseLoop << ": " << fixed << setprecision(3) << fD / sqrt(fU * fU - fV * fV) - fD / fU << endl;
		else
			cout << "Case " << nCaseLoop << ": can't determine" << endl;
	}

	return 0;
}