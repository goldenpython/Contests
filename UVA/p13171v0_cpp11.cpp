/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13171 - Pixel Art                                                */


#include <iostream>
#include <string>

using namespace std;

#define CHECK_COLOR(QUANTITY)	{ if (!QUANTITY--)	break; }

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nM, nY, nC;
		string oColors;
		cin >> nM >> nY >> nC >> oColors;

		for (char cChar : oColors)
			switch (cChar) {
				case 'B':
					CHECK_COLOR(nM); CHECK_COLOR(nY); CHECK_COLOR(nC);
					break;
				case 'G':
					CHECK_COLOR(nY); CHECK_COLOR(nC);
					break;
				case 'R':
					CHECK_COLOR(nY); CHECK_COLOR(nM);
					break;
				case 'V':
					CHECK_COLOR(nC); CHECK_COLOR(nM);
					break;
				case 'M':
					CHECK_COLOR(nM);
					break;
				case 'Y':
					CHECK_COLOR(nY);
					break;
				case 'C':
					CHECK_COLOR(nC);
					break;
			}

		if (nC < 0 || nY < 0 || nM < 0)
			cout << "NO" << endl;
		else
			cout << "YES " << nM << " " << nY << " " << nC << endl;
	}

	return 0;
}