/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12068 - Harmonic Mean                                            */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
void ReadArray(std::vector<T> &roNumbersArray) {
	int nN;
	std::cin >> nN;
	roNumbersArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(std::move(oElement));
	}
}

template <typename T>
T gcd(T a, T b) {
	T r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		vector<int> oVecnNumbers;
		ReadArray(oVecnNumbers);

		auto llNumerator = accumulate(oVecnNumbers.cbegin(), oVecnNumbers.cend(), 1LL, multiplies<long long>());
		auto llDenominator = accumulate(
			oVecnNumbers.cbegin(), 
			oVecnNumbers.cend(), 
			0LL, 
			[=] (long long llCurrent, int nCurrentElement) {
				return llCurrent + llNumerator / nCurrentElement; 
			}
		);

		auto llGCD = gcd(llNumerator *= oVecnNumbers.size(), llDenominator);
		llNumerator /= llGCD; llDenominator /= llGCD;
		cout << "Case " << nCaseLoop << ": " << llNumerator << "/" << llDenominator << endl;
	}

	return 0;
}