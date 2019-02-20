/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10730 - Antiarithmetic                                           */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	for (string oLine; getline(cin, oLine, ':'); ) {
		int nN = stoi(oLine);
		if (!nN)
			break;

		vector<int> oVecnNumbers(nN);
		for (int nLoop = 0; nLoop < nN; nLoop++) {
			int nNumber;
			cin >> nNumber;
			oVecnNumbers[nNumber] = nLoop;
		}

		bool bIsAntiarithmetic = true;
		for (int nDiff = 1; nDiff * 2 < nN; nDiff++)
			for (int nLoop = nN - 1 - nDiff * 2; nLoop >= 0; nLoop--)
				if ((oVecnNumbers[nLoop] < oVecnNumbers[nLoop + nDiff]) == (oVecnNumbers[nLoop + nDiff] < oVecnNumbers[nLoop + nDiff * 2])) {
					bIsAntiarithmetic = false;
					nDiff = nN;
					break;
				}

		cout << (bIsAntiarithmetic ? "yes" : "no") << endl;
	}

	return 0;
}