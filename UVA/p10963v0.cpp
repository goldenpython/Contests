/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10963 - The Swallowing Ground                                    */



#include <iostream>

using namespace std;

int main() {
	int nNoCases;

	for (cin >> nNoCases; nNoCases--; ) {
		int nWidth, nTop, nBottom, nDiff;
		bool bHasSol = true;
		for ((cin >> nWidth >> nTop >> nBottom), nDiff = nTop - nBottom; --nWidth; ) {
			cin >> nTop >> nBottom;
			if (nTop - nBottom != nDiff)
				bHasSol = false;
		}
		
		cout << (bHasSol ? "yes\n" : "no\n");
		if (nNoCases)
			cout << endl;
	}

	return 0;
}