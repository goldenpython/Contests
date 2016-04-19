/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12696 - Cabin Baggage                                            */


#include <iostream>
#include <utility>

using namespace std;

int main() {
	int nN, nNoValidBaggages = 0;
	for (cin >> nN; nN--;) {
		float fL, fW, fH, fWeight;
		cin >> fL >> fW >> fH >> fWeight;

		bool bValid = false;
		if (fWeight <= 7.0f) {
			if (fL + fW + fH <= 125.0f) {
				bValid = true;
			} else {
				if (fL < fW)
					swap(fL, fW);
				if (fL < fH)
					swap(fL, fH);
				if (fW < fH)
					swap(fW, fH);

				if (fL <= 56.0f && fW <= 45.0f && fH <= 25.0f)
					bValid = true;
			}
		}

		cout << (bValid ? 1 : 0) << endl;
		if (bValid)
			nNoValidBaggages++;
	}

	cout << nNoValidBaggages << endl;

	return 0;
}