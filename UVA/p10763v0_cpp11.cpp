/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10763 - Foreign Exchange                                         */


#include <iostream>
#include <unordered_map>

int main() {
	const int MAX = 500000 + 1;
	auto oHashFn = [](const std::pair<int, int> &key) { return std::hash<int>()(key.first ^ key.second); };

	for (int nN; (std::cin >> nN), nN; ) {
		std::unordered_map<std::pair<int, int>, int, decltype(oHashFn)> oMap(nN, oHashFn);

		while (nN--) {
			int nA, nB;
			std::cin >> nA >> nB;
			if (nA > nB)
				oMap[std::pair<int, int>(nB, nA)]--;
			else
				oMap[std::pair<int ,int>(nA, nB)]++;
		}

		bool bSol = true;
		for (auto oIt = oMap.begin(); oIt != oMap.end(); oIt++)
			if (oIt->second) {
				bSol = false;
				break;
			}

		std::cout << (bSol ? "YES" : "NO") << std::endl;
	}

	return 0;
}