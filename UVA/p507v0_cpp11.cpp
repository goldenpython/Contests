/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 507 - Jill Rides Again                                           */



#include <iostream>
#include <vector>

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

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoStops;
		cin >> nNoStops;

		vector<int> oVecnStopNiceness;
		ReadArray(nNoStops - 1, oVecnStopNiceness);

		int nCurentStart = 0, nCurrentNiceness = 0, nSolStart = 0, nSolEnd = 0, nSolNiceness = -1;
		for (int nLoop = 0; nLoop < oVecnStopNiceness.size(); nLoop++) {
			nCurrentNiceness += oVecnStopNiceness[nLoop];
			if (nCurrentNiceness >= 0)
				if (nSolNiceness < nCurrentNiceness || (nSolNiceness == nCurrentNiceness && nSolEnd - nSolStart < nLoop - nCurentStart))
					nSolNiceness = nCurrentNiceness, nSolStart = nCurentStart, nSolEnd = nLoop;
				else
					;
			else
				nCurentStart = nLoop + 1, nCurrentNiceness = 0;
		}

		if (nSolNiceness < 0)
			cout << "Route " << nCaseLoop << " has no nice parts" << endl;
		else
			cout << "The nicest part of route " << nCaseLoop << " is between stops " << nSolStart + 1 << " and " << nSolEnd + 2 << endl;
	}

	return 0;
}