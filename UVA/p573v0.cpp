/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 573 - The Snail                                                  */


#include <iostream>

using namespace std;

int main() {
	double fH, fU, fD, fF;

	while ((cin >> fH >> fU >> fD >> fF), fH) {
		fF *= fU / 100;
		double fCurrentUp = fU;
		double fCurrentH = fH;

		for (int nDay = 1; ; nDay++) {
			fCurrentH -= fCurrentUp;
			if (fCurrentH < 0) {
				(cout << "success on day " << nDay << endl);
				break;
			}

			fCurrentUp -= fF;
			if (fCurrentUp < 0)
				fCurrentUp = 0;

			fCurrentH += fD;
			if (fCurrentH > fH) {
				cout << "failure on day " << nDay << endl;
				break;
			}
		}

		
	}

	return 0;
}