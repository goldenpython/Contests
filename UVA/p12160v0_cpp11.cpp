/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12160 - Unlock the Lock                                          */


#include <vector>
#include <iostream>

using namespace std;

int main() {
	for (int nCaseLoop = 1; ; nCaseLoop++) {
		int nL, nU, nR;
		cin >> nL >> nU >> nR;
		if (!nL && !nU && !nR)
			break;
		vector<int> oVecnNumbers;
		for (int nLoop = 0; nLoop < nR; nLoop++) {
			int nNumber;
			cin >> nNumber;
			oVecnNumbers.push_back(nNumber);
		}

		vector<bool> oVecbVisited(10000);
		oVecbVisited[nL] = true;
		vector<int> oVecnVisitedCurrentStep(1, nL);
		int nSol = 0;
		while (!oVecbVisited[nU] && oVecnVisitedCurrentStep.size() > 0) {
			vector<int> oVecnVisitedNextStep;
			for (auto oItVisited = oVecnVisitedCurrentStep.cbegin(); oItVisited != oVecnVisitedCurrentStep.cend(); ++oItVisited) {
				for (auto oItButtonValues = oVecnNumbers.cbegin(); oItButtonValues != oVecnNumbers.cend(); ++oItButtonValues) {
					int nNewCode = (*oItVisited + *oItButtonValues) % 10000;
					if (!oVecbVisited[nNewCode]) {
						oVecbVisited[nNewCode] = true;
						oVecnVisitedNextStep.push_back(nNewCode);
					}
				}
			}
			oVecnVisitedCurrentStep = move(oVecnVisitedNextStep);
			nSol++;
		}

		if (!oVecbVisited[nU])
			cout << "Case " << nCaseLoop << ": Permanently Locked" << endl;
		else
			cout << "Case " << nCaseLoop << ": " << nSol << endl;
	}

	return 0;
}