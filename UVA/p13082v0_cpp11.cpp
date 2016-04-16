/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13082 - High School Assembly                                     */


#include <iostream>

using namespace std;

int main() {
	int nNoCases;
	cin >> nNoCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		int nNoStudents, nMaxIncConSta1SeqLen = 0, nLastHeight = 0;
		cin >> nNoStudents;
		for (int nStudentsLoop = 0; nStudentsLoop < nNoStudents; nStudentsLoop++) {
			int nHeight;
			cin >> nHeight;
			if (nHeight == nLastHeight + 1) {
				nMaxIncConSta1SeqLen++;
				nLastHeight = nHeight;
			}
		}

		cout << "Case " << nCaseLoop << ": " << nNoStudents - nMaxIncConSta1SeqLen << endl;
	}

	return 0;
}