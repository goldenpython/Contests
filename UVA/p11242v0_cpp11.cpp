/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11242 - Tour de France                                           */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

template<typename T>
void ReadArray(int nNoElements, std::vector<T> &roVecElementsArray) {
	roVecElementsArray.reserve(nNoElements);
	while (nNoElements--) {
		T oElement;
		std::cin >> oElement;
		roVecElementsArray.emplace_back(oElement);
	}
}

using namespace std;

int main() {
	for (int nF, nR; cin >> nF >> nR; ) {
		vector<int> oVecnF, oVecnR;
		ReadArray(nF, oVecnF);
		ReadArray(nR, oVecnR);

		vector<float> oVecfRatios;
		for (auto oItF = oVecnF.cbegin(); oItF != oVecnF.cend(); ++oItF)
			for (auto oItR = oVecnR.cbegin(); oItR != oVecnR.cend(); ++oItR)
				oVecfRatios.push_back(static_cast<float>(*oItR) / *oItF);

		sort(oVecfRatios.begin(), oVecfRatios.end());

		adjacent_difference(
			oVecfRatios.cbegin(),
			oVecfRatios.cend(),
			oVecfRatios.begin(),
			[] (const float fCurrent, const float fPrev) {
				return fCurrent / fPrev;
			}
		);

		auto oItMaxSpread = max_element(next(oVecfRatios.cbegin()), oVecfRatios.cend());
		cout << setprecision(2) << fixed << *oItMaxSpread << endl;
	}

	return 0;
}