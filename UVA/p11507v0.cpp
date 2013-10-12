/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11507 - Bender B. Rodríguez Problem                              */



#include <iostream>
#include <string>

using namespace std;

void swap(int &rnA, int &rnB) {
	int nTemp = rnA;
	rnA = rnB;
	rnB = nTemp;
}

int main() {
	int nLen;

	while ((cin >> nLen), nLen) {
		string oCommand;
		int nX = 1, nY = 0, nZ = 0;
		while (--nLen) {
			cin >> oCommand;

			if (oCommand == "+y") {
				swap(nX, nY);
				nX *= -1;
			} else if (oCommand == "-y") {
				swap(nX, nY);
				nY *= -1;
			} else if (oCommand == "+z") {
				swap(nX, nZ);
				nX *= -1;
			} else if (oCommand == "-z") {
				swap(nX, nZ);
				nZ *= -1;
			}
		}

		if (nX)
			cout << (nX > 0 ? "+x" : "-x") << endl;
		else if (nY)
			cout << (nY > 0 ? "+y" : "-y") << endl;
		else if (nZ)
			cout << (nZ > 0 ? "+z" : "-z") << endl;
	}

	return 0;
}