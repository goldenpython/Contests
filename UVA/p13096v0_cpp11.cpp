/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13096 - Standard Deviation                                       */


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	const int MAX = 1000000 + 1;

	vector<long long> oVecllDev;
	oVecllDev.push_back(0);	oVecllDev.push_back(0);
	for (int nLoop = 1; nLoop < MAX; nLoop++) {
		auto llPrev = oVecllDev[nLoop];
		auto llCurrent = static_cast<long long>(nLoop) * nLoop + nLoop + llPrev;
		oVecllDev.push_back(llCurrent);
	}

	for (int nN; (cin >> nN), nN; )
		cout << fixed << setprecision(6) << sqrt(static_cast<double>(oVecllDev[nN]) / (nN - 1)) << endl;

	return 0;
}