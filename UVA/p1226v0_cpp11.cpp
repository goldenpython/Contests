/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1226 - Numerical surprises                                       */


#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN;
		string oP;
		cin >> nN >> oP;

		auto nResult = accumulate(
			oP.cbegin(),
			oP.cend(),
			0,
			[nN] (int nCurrentModulo, char nChar) {
				return (nCurrentModulo * 10 + (nChar == '0' ? 0 : 1)) % nN;
			}
		);

		cout << nResult << endl;
	}

	return 0;
}