/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1594 - Ducci Sequence                                            */


#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

template<typename T>
void ReadArray(std::vector<T> &roVectElementsArray) {
	int nN;
	std::cin >> nN;
	roVectElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVectElementsArray.push_back(std::move(oElement));
	}
}

using namespace std;

int main() {


	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		vector<int> oVecnTouple;
		ReadArray(oVecnTouple);
		vector<int> oVecnToupleZero(static_cast<int>(oVecnTouple.size()), 0);

		auto oFuncHash = [](const vector<int>& roVecnTouple) -> size_t {
			// djb2 hash function
			size_t nHash = 5381;
			for (auto oIt = roVecnTouple.cbegin(); oIt != roVecnTouple.cend(); ++oIt)
				nHash += (*oIt + (nHash << 5));

			return nHash;
		};

		for (unordered_set<vector<int>, decltype(oFuncHash)> oSetTouples(1001, oFuncHash); ;) {
			if (oVecnTouple == oVecnToupleZero) {
				cout << "ZERO" << endl;
				break;
			} else if (oSetTouples.find(oVecnTouple) != oSetTouples.cend()) {
				cout << "LOOP" << endl;
				break;
			}

			oSetTouples.insert(oVecnTouple);
			int nTemp = oVecnTouple[0];
			for (int nLoop = 0, nLimit = oVecnTouple.size() - 2; nLoop <= nLimit; nLoop++)
				oVecnTouple[nLoop] = abs(oVecnTouple[nLoop] - oVecnTouple[nLoop + 1]);
			oVecnTouple[oVecnTouple.size() - 1] = abs(oVecnTouple[oVecnTouple.size() - 1] - nTemp);
		}
	}

	return 0;
}


