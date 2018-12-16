/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13145 - Wuymul Wixcha                                            */


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	for (string oLine; ; ) {
		getline(cin, oLine);
		int nOffset = stoi(oLine);
		if (!nOffset)
			break;

		getline(cin, oLine);

		const int NUM_CHARS = 'z' - 'a' + 1;
		transform(
			oLine.cbegin(), 
			oLine.cend(), 
			oLine.begin(), 
			[nOffset = nOffset + (1 + abs(nOffset / NUM_CHARS)) * NUM_CHARS] (char cChar) -> char {
				if (isupper(cChar))
					return 'A' + (cChar - 'A' + nOffset) % ('z' - 'a' + 1);
				else if (islower(cChar))
					return 'a' + (cChar - 'a' + nOffset) % ('z' - 'a' + 1);
				else
					return cChar;
			}
		);
		cout << oLine << endl;
	}

	return 0;
}