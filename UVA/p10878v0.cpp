/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10878 - Decode the tape                                          */


#include <string>
#include <iostream>

using namespace std;

int main() {
	/* freopen("input/10878.txt", "rt", stdin); */

	string sLine;
	while (getline(cin, sLine)) {
		if (sLine[0] != '|')
			continue;

		char c = 0;
		for (int i = 2; i < 10; i++) {
			if (sLine[i] == '.')
				continue;
			c = c * 2 + ((sLine[i] != ' ') ? 1 : 0);
		}
		cout << c;
	}

	return 0;
}
