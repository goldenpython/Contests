/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11986 - Save from Radiation                                      */


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nTestCaseLoop = 1; nTestCaseLoop <= nNoTestCases; nTestCaseLoop++) {
		long long llNoBottles;
		cin >> llNoBottles;
		int nAnswer = 0;
		while (llNoBottles)
			llNoBottles >>= 1, nAnswer++;
		cout << "Case "<< nTestCaseLoop << ": " << nAnswer << endl;
	}

	return 0;
}