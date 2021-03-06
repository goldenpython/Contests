/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11389 - The Bus Driver Problem                                   */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
void ReadArray(int nNoElements, std::vector<T> &roVecElementsArray) {
	roVecElementsArray.reserve(nNoElements);
	while (nNoElements--) {
		T oElement;
		std::cin >> oElement;
		roVecElementsArray.push_back(std::move(oElement));
	}
}

int main() {
	for (int nN, nD, nR; (cin >> nN >> nD >> nR), nN || nD || nR; ) {
		vector<int> oVecnMorning, oVecnEvening;
		ReadArray(nN, oVecnMorning);
		ReadArray(nN, oVecnEvening);

		sort(oVecnMorning.begin(), oVecnMorning.end(), less<int>());
		sort(oVecnEvening.begin(), oVecnEvening.end(), greater<int>());

#if defined(_MSC_VER) && (_MSC_VER <= 1600)
		const auto nMaxLengthIfNoExtraPayment = nD, nPaymentPerDay = nR;
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)
		auto nResult = accumulate(
			oVecnMorning.begin(),
			transform(
				oVecnMorning.cbegin(),
				oVecnMorning.cend(),
				oVecnEvening.cbegin(),
				oVecnMorning.begin(),
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
				[nMaxLengthIfNoExtraPayment = nD, nPaymentPerDay = nR] (int nMorning, int nEvening) {
#else
				[nMaxLengthIfNoExtraPayment, nPaymentPerDay] (int nMorning, int nEvening) {
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
					return max(0, nMorning + nEvening - nMaxLengthIfNoExtraPayment) * nPaymentPerDay;
				}
			),
			0
		);

		cout << nResult << endl;
	}

	return 0;
}