/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13209 - My Password is a Palindromic Prime Number                */


#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN, nNumerator = 1;
		cin >> nN;

		unordered_set<int> oSetRemainders;

		cout << "0.";
		while (true) {
			int nTemp = (nNumerator * 10) / nN;
			nNumerator = (nNumerator * 10) % nN;

			if (oSetRemainders.find(nNumerator) != oSetRemainders.cend())
				break;
			oSetRemainders.insert(nNumerator);
			cout << nTemp;
			
		}

		cout << endl;
	}

	return 0;
}
