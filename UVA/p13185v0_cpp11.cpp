/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13185 - DPA Numbers I                                            */


#include <memory>
#include <string>
#include <iostream>
#include <vector>

std::shared_ptr<std::string> ComputeCategory(int nN) {
	static const std::shared_ptr<std::string> PERFECT = std::make_shared<std::string>("perfect");
	static const std::shared_ptr<std::string> DEFICIENT = std::make_shared<std::string>("deficient");
	static const std::shared_ptr<std::string> ABUNDANT = std::make_shared<std::string>("abundant");

	if (nN <= 1)
		return DEFICIENT;

	int nDiv = 2, nSum = 1;
	for ( ; nDiv * nDiv < nN; nDiv++) {
		if (!(nN % nDiv)) {
			nSum += nDiv + nN / nDiv;
			if (nSum > nN)
				return ABUNDANT;
		}
	}

	if (nDiv * nDiv == nN)
		nSum += nDiv;

	if (nSum < nN)
		return DEFICIENT;
	else if (nSum == nN)
		return PERFECT;
	else 
		return ABUNDANT;
}

std::shared_ptr<std::string> GetCategory(int nN) {
	static const int MAX = 1000 + 1;
	static std::vector<std::shared_ptr<std::string>> oVecCategory(MAX);

	if (!oVecCategory[nN])
		oVecCategory[nN] = ComputeCategory(nN);

	return oVecCategory[nN];
}

int main() {
	int nNoTestCases;
	std::cin >> nNoTestCases;
	while (nNoTestCases--) {
		int nN;
		std::cin >> nN;
		std::cout << *GetCategory(nN) << std::endl;
	}

	return 0;
}