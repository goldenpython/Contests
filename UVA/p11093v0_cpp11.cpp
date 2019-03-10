/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11093 - Just Finish it up                                        */



#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roVecNumbersArray) {
	roVecNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roVecNumbersArray.push_back(oElement);
	}
}

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nN;
		cin >> nN;

		vector<int> oVecnP, oVecnQ;
		ReadArray(nN, oVecnP);
		ReadArray(nN, oVecnQ);

		int nSolIndex = 0;
		do {
			transform(oVecnP.cbegin(), oVecnP.cend(), oVecnQ.cbegin(), oVecnP.begin(), minus<int>());
			auto nSum = accumulate(oVecnP.cbegin(), oVecnP.cend(), 0);
			if (nSum < 0) {
				nSolIndex = -1;
				break;
			}

			partial_sum(oVecnP.cbegin(), oVecnP.cend(), oVecnQ.begin());
			auto nMinDiff = *min_element(oVecnQ.cbegin(), oVecnQ.cend());
			if (nMinDiff >= 0)
				break;

			oVecnP[0] = nMinDiff - oVecnP[0];
			partial_sum(oVecnP.cbegin(), oVecnP.cend(), oVecnP.begin(), minus<int>());
			auto oIt = find_if(oVecnP.cbegin(), oVecnP.cend(), [] (int nNumber) { return nNumber >= 0; });
			if (oIt == oVecnP.cend())
				nSolIndex = -1;
			else
				nSolIndex = distance(oVecnP.cbegin(), oIt);


		} while (false);

		cout << "Case " << nCaseLoop << ": ";
		if (nSolIndex < 0)
			cout << "Not possible" << endl;
		else
			cout << "Possible from station " << (nSolIndex + 2) << endl;
	}

	return 0;
}