/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10759 - Dice Throwing                                            */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T>
T gcd(T a, T b) {
	T r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

int main() {
	const int MAX_THROWS = 24;
	const int MAX_SIZE = 151;
	typedef unsigned long long RESULT_TYPE;
	vector<vector<RESULT_TYPE>> oVecSol = vector<vector<RESULT_TYPE>>(MAX_THROWS + 1, vector<RESULT_TYPE>(MAX_SIZE));

	oVecSol[0][0] = 1;
	for (auto oItThrow = next(oVecSol.begin()); oItThrow != oVecSol.end(); ++oItThrow) {
		auto oItPrevThrow = prev(oItThrow);
		auto nIndex = distance(oVecSol.begin(), oItPrevThrow);
		for (int nLoop = 1; nLoop <= 6; nLoop++) {
			transform(
				next(oItPrevThrow->cbegin(), nIndex),
				next(oItPrevThrow->cbegin(), nIndex * 6 + 1),
				next(oItThrow->cbegin(), nIndex + nLoop),
				next(oItThrow->begin(), nIndex + nLoop),
				plus<RESULT_TYPE>()
			);
		}

		//oItPrevThrow->resize(nIndex * 6 + 1);
		// partial_sum(oItPrevThrow->rbegin(), oItPrevThrow->rend(), oItPrevThrow->rbegin());
	}

	for (auto oItThrow = oVecSol.begin(); oItThrow != oVecSol.end(); ++oItThrow) {
		auto nIndex = distance(oVecSol.begin(), oItThrow);
		oItThrow->resize(nIndex * 6 + 1);
		partial_sum(oItThrow->rbegin(), oItThrow->rend(), oItThrow->rbegin());
		oItThrow->resize(MAX_SIZE);
	}


	for (int nN, nX; (cin >> nN >> nX), nN || nX; ) {
		auto llTotal = oVecSol[nN][0];
		auto llNoPossibilities = oVecSol[nN][nX];
		if (llNoPossibilities == 0) {
			cout << '0' << endl;
			continue;
		}
		auto llGCD = gcd(llNoPossibilities, llTotal);
		llTotal /= llGCD; llNoPossibilities /= llGCD;

		if (llTotal == 1)
			cout << llNoPossibilities << endl;
		else
			cout << llNoPossibilities << '/' << llTotal << endl;
	}

	return 0;
}