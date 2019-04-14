/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13187 - Felipe and the Sequence                                  */


#include <iostream>

/*
	1 / (sqrt(n + 1) + sqrt(n)) = sqrt(n + 1) - sqrt(n)
	thus
	the sum equals sqrt(n + 1) + 1
*/

int main() {
	int nNoTestCases;
	for (std::cin >> nNoTestCases; nNoTestCases--; ) {
		int nS;
		std::cin >> nS;
		std::cout << static_cast<long long>(nS + 1) * (nS + 1) - 1 << std::endl;
	}

	return 0;
}