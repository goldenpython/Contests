/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12908 - The book thief                                           */


#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void QESolver(const T &rtA, const T &rtB, const T &rtC, T &rtX1, T &rtX2) {
	T tDelta = sqrt(rtB * rtB - 4 * rtA * rtC);
	rtX1 = (-rtB + tDelta) / 2 / rtA;
	rtX2 = (-rtB - tDelta) / 2 / rtA;
}

int main() {
	int nS;
	while ((cin >> nS), nS) {
		typedef float REAL;
		REAL fX1, fX2;

		QESolver<float>(1, 1, -2 * (nS + 1), fX1, fX2);
		REAL fMin = max(fX1, fX2);

		QESolver<float>(1, -1, -2 * nS, fX1, fX2);
		REAL fMax = max(fX1, fX2);


		int nNoPagesMin = static_cast<int>(ceil(fMin));
		int nNoPagesMax = static_cast<int>(floor(fMax));
		for (int nNoPages = nNoPagesMin; nNoPages <= nNoPagesMax; nNoPages++) {
			int nPageMissing = nNoPages * (1 + nNoPages) / 2 - nS;
			if (nPageMissing >= 1 && nPageMissing <= nNoPages) {
				std::cout << nPageMissing << " " << nNoPages << std::endl;
				break;
			}
		}
	}

	return 0;
}