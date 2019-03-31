/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 537 - Artificial Intelligence?                                   */


#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	string oLine;
	getline(cin, oLine);
	for (int nNoTestCases = stoi(oLine), nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		static const regex CONCEPT_REGEXPR("[IUP]=");
		static const regex UNIT_REGEXPR("[mkM]?[VWA]");

		double lfU, lfI, lfP;
		lfU = lfI = lfP = -1.0f;

		getline(cin, oLine);

		std::smatch oMatchConcept, oMatchUnit;
		while (regex_search(oLine, oMatchConcept, CONCEPT_REGEXPR)) {
			double *plfConcept = nullptr;
			switch (oMatchConcept[0].str()[0]) {
				case 'U':
					plfConcept = &lfU;
					break;
				case 'I':
					plfConcept = &lfI;
					break;
				case 'P':
					plfConcept = &lfP;
					break;
			}

			regex_search(oLine.cbegin() + oMatchConcept.position(0) + 2, oLine.cend(), oMatchUnit, UNIT_REGEXPR);

			*plfConcept = stod(oMatchUnit.prefix());

			switch (oMatchUnit[0].str()[0]) {
				case 'm':
					*plfConcept /= 1000;
					break;
				case 'M':
					*plfConcept *= 1000000;
					break;
				case 'k':
					*plfConcept *= 1000;
					break;					
			}

			oLine = oMatchUnit.suffix().str();
		}

		cout << "Problem #" << nCaseLoop << endl;
		if (lfP < 0)
			cout << "P=" << lfU * lfI << 'W' << endl;
		else if (lfI < 0)
			cout << "I=" << lfP / lfU << 'A' << endl;
		else if (lfU < 0)
			cout << "U=" << lfP / lfI << 'V' << endl;
		cout << endl;
	}

	return 0;
}