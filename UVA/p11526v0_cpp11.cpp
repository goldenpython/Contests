/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11526 - H(n)                                                     */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN;
		cin >> nN;

		if (nN < 0) {
			cout << 0 << endl;
			continue;
		}
		
		long long llResult = 0;
		for (int nNDivIResult = 1; ; ) {
			auto nLeft = nN / (nNDivIResult + 1);
			auto nRight = nN / nNDivIResult;
			llResult += (nRight - nLeft) * nNDivIResult;
			if (!nLeft)
				break;
			nNDivIResult = nN / nLeft;
		}

		cout << llResult << endl;
	}

	return 0;
}