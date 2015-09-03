/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10137 - The Trip                                                 */


#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	for (int nNoStudents; (cin >> nNoStudents), nNoStudents; ) {
		vector<double> oVecAmounts;

		double fMedian1 = 0;
		for (int nLoop = 0; nLoop < nNoStudents; nLoop++) {
			double fValue;
			cin >> fValue;
			fMedian1 += fValue;
			oVecAmounts.push_back(fValue);
		}

		fMedian1 /= nNoStudents;

		double fSol1 = 0, fSol2 = 0;
		for (int nLoop = 0; nLoop < nNoStudents; nLoop++) {
			if (oVecAmounts[nLoop] > fMedian1)
				fSol1 += floor((oVecAmounts[nLoop] - fMedian1) * 100) / 100;
			if (oVecAmounts[nLoop] < fMedian1)
				fSol2 += floor((fMedian1 - oVecAmounts[nLoop]) * 100) / 100;
		}
		
		cout << "$" << setprecision(2) << fixed << (floor((fSol1 > fSol2 ? fSol1 : fSol2) * 100 + 0.5) / 100) << endl;
	}

	return 0;
}

