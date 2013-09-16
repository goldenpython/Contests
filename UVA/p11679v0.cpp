/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11679 - Sub-prime                                                */



#include <iostream>

using namespace std;

int main() {
	const int MAX_BANKS = 20;

	int nNoBanks, nNoDebentures;
	int arrnReserves[MAX_BANKS];

	for ( ; (cin >> nNoBanks >> nNoDebentures), nNoBanks && nNoDebentures; ) {
		int nBankLoop;

		for (nBankLoop = 0; nBankLoop < nNoBanks; nBankLoop++)
			cin >> arrnReserves[nBankLoop];

		for (int nLoop = 0; nLoop < nNoDebentures; nLoop++) {
			int nDebtor, nCreditor, nValue;
			cin >> nDebtor >> nCreditor >> nValue;
			arrnReserves[nDebtor - 1] -= nValue;
			arrnReserves[nCreditor - 1] += nValue;
		}
		
		for (nBankLoop = 0; nBankLoop < nNoBanks; nBankLoop++)
			if (arrnReserves[nBankLoop] < 0) {
				nBankLoop = -1;
				break;
			}

		cout << (nBankLoop < 0 ? "N\n" : "S\n");
	}

	return 0;
}