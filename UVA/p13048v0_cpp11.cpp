/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13048 - Burger Stand                                             */


#include <iostream>
#include <string>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 0; nCaseLoop++ < nNoTestCases; ) {
		string oLine;
		cin >> oLine;
		int nNoPositions = 0;
		for (auto oIt = oLine.cbegin(); oIt < oLine.cend(); ++oIt) {
			switch (*oIt) {
				case 'B':
				case 'D':
				case 'S':
				default:
					continue;
				case '-':
					if (oLine.cend() - oIt > 2 && *(oIt + 2) == 'B') 
						continue;

					if (oLine.cend() - oIt > 1 && (*(oIt + 1) == 'B' || *(oIt + 1) == 'S'))
						continue;

					if (oIt - oLine.cbegin() >= 1 && *(oIt - 1) == 'S')
						continue;

					nNoPositions++;
			}

		}

		cout << "Case " << nCaseLoop << ": " << nNoPositions << endl;
	}

	return 0;
}