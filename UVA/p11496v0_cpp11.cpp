/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11496 - Musical Loop                                             */


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
void ReadArray(std::vector<T> &roNumbersArray) {
	int nN;
	std::cin >> nN;
	roNumbersArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}

int Sgn(int nNumber) {
	if (!nNumber)
		return 0;

	return nNumber < 0 ? -1 : 1;
}

int main() {
	while (true) {
		vector<int> oVecnMagnitudes;
		ReadArray(oVecnMagnitudes);
		if (!oVecnMagnitudes.size())
			break;

		typedef struct {
			int m_nPrev, m_nPrev2, nNoPeaks;
		} STATE;

		STATE oCurrentState = { *(oVecnMagnitudes.crbegin()), *(next(oVecnMagnitudes.crbegin())), 0 };

		oCurrentState = accumulate(
			oVecnMagnitudes.cbegin(),
			oVecnMagnitudes.cend(),
			oCurrentState,
			[] (STATE oCurrentState, int nCurrentNumber) {
				int nSign = Sgn(oCurrentState.m_nPrev2 - oCurrentState.m_nPrev) * Sgn(oCurrentState.m_nPrev - nCurrentNumber);
				if (nSign < 0)
					oCurrentState.nNoPeaks++;
				oCurrentState.m_nPrev2 = oCurrentState.m_nPrev;
				oCurrentState.m_nPrev = nCurrentNumber;
				return oCurrentState;
			}
		);

		cout << oCurrentState.nNoPeaks << endl;
	}

	return 0;
}