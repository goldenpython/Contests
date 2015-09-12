/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12810 - Sumthing                                                 */


#include <iostream>

using namespace std;

int main() {
	int nNoCases;
	for (cin >> nNoCases; nNoCases--;) {
		const int BASE = 1000000009LL;
		int nN;
		long long nSol = 1LL;
		for (cin >> nN; nN--;) {
			int nNumber;
			cin >> nNumber;
			nSol = (nSol * (1 + 2 * nNumber)) % BASE;
		}

		nSol = (nSol - 1) * 500000005 % BASE;
		cout << nSol << endl;
	}

	return 0;
}