/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12036 - Stable Grid                                              */


#include <iostream>
#include <vector>

int main() {
	int nNoTestCases;
	std::cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nN;
		std::cin >> nN;
		int nNPow2 = nN * nN;
		std::vector<int> oVecFreq(101);
		bool bSol = true;
		for (int nLoop = 0; nLoop < nNPow2; nLoop++) {
			int nNumber;
			std::cin >> nNumber;
			if (++oVecFreq[nNumber] > nN) {
				bSol = false;
			}
		}

		std::cout << "Case " << nCaseLoop << ": " << (bSol ? "yes" : "no") << std::endl;
	}

	return 0;
}