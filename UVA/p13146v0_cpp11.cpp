/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13146 - Edid Tistance                                            */


#include <iostream>
#include <string>
#include <vector>

int Levenshtein(const std::string &roString1, const std::string &roString2) {
	std::vector<std::vector<int>> oVec2nDist(roString1.size() + 1, std::vector<int>(roString2.size() + 1));
	for (size_t nLoop1 = 0; nLoop1 <= roString1.size(); nLoop1++)
		oVec2nDist[nLoop1][0] = nLoop1;
	for (size_t nLoop2 = 0; nLoop2 <= roString2.size(); nLoop2++)
		oVec2nDist[0][nLoop2] = nLoop2;

	for (size_t nLoop1 = 1; nLoop1 <= roString1.size(); nLoop1++) {
		for (size_t nLoop2 = 1; nLoop2 <= roString2.size(); nLoop2++) {
			int nMin = std::min(oVec2nDist[nLoop1 - 1][nLoop2], oVec2nDist[nLoop1][nLoop2 - 1]) + 1;
			oVec2nDist[nLoop1][nLoop2] = std::min(nMin, oVec2nDist[nLoop1 - 1][nLoop2 - 1] + (roString1[nLoop1 - 1] != roString2[nLoop2 - 1]));
		}
	}

	return oVec2nDist[roString1.size()][roString2.size()];
}

int main() {
	std::string oString1, oString2;
	int nNoPairs;
	std::getline(std::cin, oString1);
	nNoPairs = std::stoi(oString1);

	while (nNoPairs--) {
		std::getline(std::cin, oString1);
		std::getline(std::cin, oString2);
		std::cout << Levenshtein(oString1, oString2) << std::endl;
	}

	return 0;
}