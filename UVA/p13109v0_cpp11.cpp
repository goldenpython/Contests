/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13109 - Elephants                                                */


#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roNumbersArray) {
	roNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}

int main() {
	int nNoTestCasesLeft;
	std::cin >> nNoTestCasesLeft;
	while (nNoTestCasesLeft--) {
		int nM, nW;
		std::cin >> nM >> nW;
		std::vector<int> arrnWeights;
		ReadArray(nM, arrnWeights);

		std::sort(arrnWeights.begin(), arrnWeights.end());
		int nSol = 0, nCurrentWeight = 0;
		while (nSol < nM) {
			nCurrentWeight += arrnWeights[nSol];
			if (nCurrentWeight > nW)
				break;
			nSol++;
		}
		std::cout << nSol << std::endl;
	}

	return 0;
}