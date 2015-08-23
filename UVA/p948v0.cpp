/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 948 - Fibonaccimal Base                                          */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	const int MAX = 100000000;
	vector<int> oVecFib;
	
	oVecFib.push_back(0); oVecFib.push_back(1); oVecFib.push_back(2);
	for (int nLoop = oVecFib.size() - 1; ; nLoop++) {
		int nCurrent = oVecFib[nLoop - 1] + oVecFib[nLoop];
		oVecFib.push_back(nCurrent);
		if (nCurrent > MAX)
			break;
	}

	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN;
		cin >> nN;

		auto oIt = upper_bound(oVecFib.begin(), oVecFib.end(), nN);
		if (*oIt > nN)
			oIt--;
		
		cout << nN << " = ";
		for (bool bForceZero = false; oIt > oVecFib.begin(); oIt--) {
			if (nN >= *oIt && !bForceZero) {
				cout << "1";
				nN -= *oIt;
				bForceZero = true;
			} else {
				cout << "0";
				bForceZero = false;
			}
		}

		cout << " (fib)" << endl;
		
	}

	return 0;
}