/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12853 - The Pony Cart Problem                                    */


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int nNoCases;
	cin >> nNoCases;

	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		double fD, fN;
		cin >> fD >> fN;
		cout << "Case " << nCaseLoop << ": " << setprecision(3) << fixed << atan(static_cast<double>(1.0)) * 8 * (fD / (fN - 1) + fD) << endl;
	}

	return 0;
}