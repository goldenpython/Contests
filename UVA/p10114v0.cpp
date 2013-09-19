/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10114 - Loansome Car Buyer                                       */




#include <iostream>

using namespace std;

int main() {
	int nNoMonths, nNoDepreciationRecords;
	double fDownPayment, fLoan;

	while ((cin >> nNoMonths >> fDownPayment >> fLoan >> nNoDepreciationRecords), nNoMonths > 0) {
		int nMonth = 0;
		int nMonthNumber;
		double fDepreciationPercent;
		double fValue = fLoan + fDownPayment;
		fDownPayment = fLoan / nNoMonths;
		int nSol = -1;

		cin >> nMonthNumber >> fDepreciationPercent;

		for (int nLoop = 1; nLoop <= nNoDepreciationRecords; nLoop++) {
			double fNewDepreciationPercent;

			if (nLoop == nNoDepreciationRecords) {
				nMonthNumber = nNoMonths + 1;
				fNewDepreciationPercent = fDepreciationPercent;
			} else {
				cin >> nMonthNumber >> fNewDepreciationPercent;
			}

			for (; nMonth < nMonthNumber; nMonth++) {
				fValue *= (1 - fDepreciationPercent);
				if (fValue > fLoan && nSol == -1) {
					nSol = nMonth;
				}
				fLoan -= fDownPayment;
			}

			fDepreciationPercent = fNewDepreciationPercent;
		}

		cout << nSol << (nSol != 1 ? " months" : " month") << endl;
	}

	return 0;
}