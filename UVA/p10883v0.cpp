/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10883 - Supermean                                                */


#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

template<typename T>
void ReadArray(std::vector<T> &roNumbersArray) {
	int nN;
	std::cin >> nN;
	roNumbersArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}

int main() {
	const int MAX = 50000 + 1;
	std::vector<double> oLogFactorials(MAX);
	for (int nLoop = 1; nLoop < MAX; nLoop++)
		oLogFactorials[nLoop] = oLogFactorials[nLoop - 1] + std::log(static_cast<double>(nLoop));

	int nNoCases;
	std::cin >> nNoCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		std::vector<double> oNumbers;
		ReadArray(oNumbers);
		const int nNoNumbers = oNumbers.size();

		double fDenominator = (nNoNumbers - 1) * std::log(2.0);
		double fTotal = (oNumbers[0] + (nNoNumbers > 1 ? oNumbers[nNoNumbers - 1] : 0.0)) / std::exp(fDenominator);
		for (int nLoop = 1; nLoop < nNoNumbers - 1; nLoop++) {
			double fNum = oLogFactorials[nNoNumbers - 1] - oLogFactorials[nLoop] - oLogFactorials[nNoNumbers - 1 - nLoop] - fDenominator;
			fTotal += oNumbers[nLoop] * std::exp(fNum);
		}

		std::cout << "Case #" << nCaseLoop << ": " << std::setprecision(3) << std::fixed << fTotal << std::endl;
	}

	return 0;
}