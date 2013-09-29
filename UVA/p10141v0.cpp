/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10141 - Request for Proposal                                     */


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int nNoRequirements, nNoProposals, nCase = 0;

	while (1) {
		string oLine;
		getline(cin, oLine);
		stringstream oStream(oLine);
		oStream >> nNoRequirements >> nNoProposals;

		if (!(nNoRequirements && nNoProposals))
			break;

		for (int nLoopRequirements = 0; nLoopRequirements < nNoRequirements; nLoopRequirements++) {
			string oRequirement;
			getline(cin, oRequirement);
		}

		int nMaxRequirements = -1;
		double fMinPrice;
		string oSol;

		for (int nLoopProposals = 0; nLoopProposals < nNoProposals; nLoopProposals++) {
			int nRequirementsMet;
			double fPrice;
			string oProposal;
			getline(cin, oProposal);

			getline(cin, oLine);
			stringstream oStream(oLine);
			oStream >> fPrice >> nRequirementsMet;

			for (int nLoopRequirements = 0; nLoopRequirements < nRequirementsMet; nLoopRequirements++) {
				string oRequirement;
				getline(cin, oRequirement);
			}

			if (nRequirementsMet > nMaxRequirements) {
				nMaxRequirements = nRequirementsMet;
				fMinPrice = fPrice;
				oSol = oProposal;
			} else if (nRequirementsMet == nMaxRequirements && fMinPrice > fPrice) {
				fMinPrice = fPrice;
				oSol = oProposal;
			}
		}

		if (nCase++)
			cout << endl;
		cout << "RFP #" << nCase << endl << oSol << endl;
	}

	return 0;
}