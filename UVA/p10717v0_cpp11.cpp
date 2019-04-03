/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10717 - Mint                                                     */


#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

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

template <typename T>
T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roVecNumbersArray) {
	roVecNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roVecNumbersArray.push_back(std::move(oElement));
	}
}

using namespace std;

int main() {
	for (int nN, nT; (cin >> nN >> nT), (nN || nT); ) {
		vector<int> oVecnThickness;
		ReadArray(nN, oVecnThickness);

		unordered_set<int> oSetLCMs;
		for (auto oIt1 = oVecnThickness.cbegin(); oIt1 != oVecnThickness.cend(); ++oIt1) {
			for (auto oIt2 = next(oIt1); oIt2 != oVecnThickness.cend(); ++oIt2) {
				auto nLCM12 = lcm(*oIt1, *oIt2);
				for (auto oIt3 = next(oIt2); oIt3 != oVecnThickness.cend(); ++oIt3) {
					auto nLCM123 = lcm(nLCM12, *oIt3);
					for (auto oIt4 = next(oIt3); oIt4 != oVecnThickness.cend(); ++oIt4) {
						auto nLCM1234 = lcm(nLCM123, *oIt4);
						oSetLCMs.insert(nLCM1234);
					}
				}
			}
		}

		while (nT--) {
			int nTableHeight;
			cin >> nTableHeight;
			int nMax = -1, nMin = -1;
			for_each(
				oSetLCMs.cbegin(), 
				oSetLCMs.cend(),
				[&nMax, &nMin, nTableHeight] (int nLCM) {
					auto nH = nTableHeight / nLCM * nLCM;
					if (nH > nMax)
						nMax = nH;

					if (nH < nTableHeight)
						nH += nLCM;
					if (nH < nMin || nMin < 0)
						nMin = nH;
				}
			);

			cout << nMax << ' ' << nMin << endl;
		}
	}

	return 0;
}