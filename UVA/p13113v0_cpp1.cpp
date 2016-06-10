/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13113 - Presidential Election                                    */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roNumbersArray) {
	roNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--;) {
		int nNoCandidates, nNoStates;
		cin >> nNoCandidates >> nNoStates;
		vector<long long> arrllTotalVotesPerCandidate(nNoCandidates + 1, 0);
		long long llTotalVoters = 0;
		for (int nStateLoop = 0; nStateLoop < nNoStates; nStateLoop++) {
			vector<double> arrlfPercents;
			ReadArray(nNoCandidates, arrlfPercents);
			int nVoters;
			cin >> nVoters;
			llTotalVoters += nVoters;

			transform(
				arrlfPercents.cbegin(), 
				arrlfPercents.cend(), 
				arrllTotalVotesPerCandidate.cbegin(), 
				arrllTotalVotesPerCandidate.begin(), 
				[nVoters](const double &f, const long long &ll) {
					return ll + lround(f / 100 * nVoters); 
				}
			);
		}

		const long long *oItMax = arrllTotalVotesPerCandidate.data() + nNoCandidates, *oItMax1 = arrllTotalVotesPerCandidate.data() + nNoCandidates;
		for_each(
			arrllTotalVotesPerCandidate.cbegin(), 
			arrllTotalVotesPerCandidate.cend(), 
			[&oItMax, &oItMax1](const long long &llElement) {
				if (*oItMax < llElement) {
					oItMax1 = oItMax;
					oItMax = &llElement;
				} else if (*oItMax1 < llElement) {
					oItMax1 = &llElement;
				}
			}
		);

		cout << (oItMax - arrllTotalVotesPerCandidate.data()) + 1 << " " << *oItMax << endl;
		if (static_cast<double>(*oItMax) / llTotalVoters < 0.501) 
			cout << (oItMax1 - arrllTotalVotesPerCandidate.data()) + 1 << " " << *oItMax1 << endl;
		if (nNoTestCasesLeft)
			cout << endl;
		
	}

	return 0;
}