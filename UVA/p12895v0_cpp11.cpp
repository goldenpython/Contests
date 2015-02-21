/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12895 - Armstrong Number                                         */


#include <iostream>
#include <string>
#include <algorithm>

int main() {
	const int MAX_DIGITS = 11;
	unsigned int arrPowers[MAX_DIGITS][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	for (int nLoopPower = 1; nLoopPower < MAX_DIGITS; nLoopPower++)
		for (int nLoopDigit = 0; nLoopDigit < 10; nLoopDigit++)
			arrPowers[nLoopPower][nLoopDigit] = nLoopDigit * arrPowers[nLoopPower - 1][nLoopDigit];

	int nNoCases;
	for (std::cin >> nNoCases; nNoCases--; ) {
		unsigned int nNumber;
		std::cin >> nNumber;

		std::string oNumber = std::to_string((long long)nNumber);

		unsigned int nSum = 0;
		std::for_each(oNumber.begin(), oNumber.end(), [&nSum, &arrPowers, &oNumber](char &c) { nSum += arrPowers[oNumber.size()][c - '0']; });

		if (nSum == nNumber)
			std::cout << "Armstrong" << std::endl;
		else
			std::cout << "Not Armstrong" << std::endl;
	}

	return 0;
}