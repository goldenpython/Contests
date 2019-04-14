/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13142 - Destroy the Moon to Save the Earth                       */


#include <iostream>

int main() {
	int nNoTestCasesLeft;
	for (std::cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		double lfT, lfS, lfD;
		std::cin >> lfT >> lfS >> lfD;
		double lfResult = (lfD * 1000 * 1000) / (lfT * 24 * 60 * 60);
		int nResult = abs(static_cast<int>(lfResult));
		std::cout << ((lfResult > 0 && nResult > 0) ? "Remove " : "Add ") << nResult << " tons" << std::endl;
	}

	return 0;
}