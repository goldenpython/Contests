/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11729 - Commando War                                             */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

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

struct SOLDIER {
	int nBriefingTime, nJobTime;
	bool operator < (const SOLDIER &roRHS) const { return this->nJobTime > roRHS.nJobTime; }
};

istream& operator >> (istream &roInputStream, SOLDIER &roSoldier) {
	roInputStream >> roSoldier.nBriefingTime >> roSoldier.nJobTime;
	return roInputStream;
}

int main() {
	for (int nCaseNumber = 1; ; nCaseNumber++) {
		vector<SOLDIER> oVecSoldiers;
		ReadArray(oVecSoldiers);
		if (!oVecSoldiers.size())
			break;

		sort(oVecSoldiers.begin(), oVecSoldiers.end());

		SOLDIER oSol = {0, 0};
		oSol = accumulate(
			oVecSoldiers.begin(),
			oVecSoldiers.end(),
			oSol,
			[] (SOLDIER &roPartialSolution, const SOLDIER &roCurrentElement) -> SOLDIER {
				roPartialSolution.nBriefingTime += roCurrentElement.nBriefingTime;
				roPartialSolution.nJobTime = max(roPartialSolution.nJobTime, roPartialSolution.nBriefingTime + roCurrentElement.nJobTime);
				return roPartialSolution;
			} 
		);
		
		cout << "Case " << nCaseNumber << ": " << oSol.nJobTime << endl;
	}
	return 0;
}