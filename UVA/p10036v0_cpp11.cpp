/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10036 - Divisibility                                             */


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN, nK;
		cin >> nN >> nK;
		vector<int> oVecNumbers;
		for (int nLoop = 0; nLoop < nN; nLoop++) {
			int nNumber;
			cin >> nNumber;
			nNumber= ((nNumber % nK) + nK) % nK;
			oVecNumbers.push_back(nNumber);
		}

		unordered_set<int> oSetSol;
		oSetSol.insert(0);
		for (auto oItNumber = oVecNumbers.begin(); oItNumber != oVecNumbers.end(); oItNumber++) {
			unordered_set<int> oSetCurrentStep;
			for (auto oItStepSum = oSetSol.begin(); oItStepSum != oSetSol.end(); oItStepSum++) {
				oSetCurrentStep.insert((*oItStepSum + *oItNumber) % nK);
				oSetCurrentStep.insert((*oItStepSum - *oItNumber + nK) % nK);
			}

			oSetSol.swap(oSetCurrentStep);
		}

		cout << (oSetSol.find(0) != oSetSol.end() ? "Divisible\n" : "Not divisible\n");
	}

	return 0;
}