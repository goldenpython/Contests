/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10375 - Choose and divide                                        */


#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void Comb(int nN, int nK, vector<int> &roVecnExponents, int nSign) {
	int nK2 = nK > nN / 2 ? nK : nN - nK;

	for (int nLoop = nK2 + 1; nLoop <= nN; nLoop++)
		roVecnExponents[nLoop] += nSign;
	for (int nLoop = nN - nK2; nLoop >= 2; nLoop--)
		roVecnExponents[nLoop] -= nSign;
}

int main() {
	for (int nP, nQ, nR, nS; cin >> nP >> nQ >> nR >> nS; ) {
		const int MAX_NUMBER = 10001;
		vector<int> nPow(MAX_NUMBER);
		Comb(nP, nQ, nPow, 1);
		Comb(nR, nS, nPow, -1);

		long double llfRes = 0;
		for (int nLoop = max(max(nP, nQ), max(nR, nS)); nLoop >= 2; nLoop--)
			if (nPow[nLoop])
				llfRes += nPow[nLoop] * logl(nLoop);

		cout << setprecision(5) << fixed << expl(llfRes) << endl;
	}

	return 0;
}