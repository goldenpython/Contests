/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11231 - Black and white painting                                 */


#include <iostream>

using namespace std;

int main() {
	int nN, nM, nC;

	while ((cin >> nN >> nM >> nC), nN || nM || nC) {
		int nSol = ((nC + nN - 7) / 2) * ((nM - 6) / 2) + ((1 - nC + nN - 7) / 2) * ((nM - 7) / 2);
		cout << nSol << endl;
	}

	return 0;
}