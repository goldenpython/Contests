/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12457 - Tennis contest                                           */


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <typename T>
T CombSimple(int nN, int nK) {
	T tResult(1);

	for (int nLoop = nN - nK + 1; nLoop <= nN; nLoop++) {
		tResult *= static_cast<T>(nLoop);
		tResult /= static_cast<T>(nN - nLoop + 1);
	}

	return tResult;
}

template <typename T>
T ProbabilityAWinsTitleInTotalMatches(double lfMatchWinProbability, int nTotalMatches, int nN) {
	auto lfResult = CombSimple<T>(nTotalMatches - 1, nTotalMatches - nN);
	lfResult *= pow(lfMatchWinProbability, nN);
	lfResult *= pow(1 - lfMatchWinProbability, nTotalMatches - nN);

	return lfResult;
}

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN;
		double lfWinProbability;
		while (cin >> nN >> lfWinProbability) {
			double lfAnswer(0);

			for (int nTotalMatches = 2 * nN - 1; nTotalMatches >= nN; nTotalMatches--)
				lfAnswer += ProbabilityAWinsTitleInTotalMatches<double>(lfWinProbability, nTotalMatches, nN);

			cout << setprecision(2) << fixed << lfAnswer << endl;
		}
	}

	return 0;
}