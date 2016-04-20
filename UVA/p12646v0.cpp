/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12646 - Zero or One                                              */


#include <iostream>

using namespace std;

int main() {
	int nA, nB, nC;
	while (cin >> nA >> nB >> nC) {
		if (nA != nB && nB == nC)
			cout << 'A' << endl;
		else if (nB != nA && nA == nC)
			cout << 'B' << endl;
		else if (nC != nA && nA == nB)
			cout << 'C' << endl;
		else
			cout << '*' << endl;
	}

	return 0;
}