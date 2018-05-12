/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10642 - Can You Solve It?                                        */


#include <iostream>

using namespace std;

int GetLine(int nX, int nY) {
	return nX + nY;
}

int main() {
	int nNoTestCases, nTestCaseLoop;
	for (cin >> nNoTestCases, nTestCaseLoop = 1; nTestCaseLoop <= nNoTestCases; nTestCaseLoop++) {
		int nX1, nY1, nX2, nY2;
		cin >> nY1 >> nX1 >> nY2 >> nX2;
		int nLine1 = GetLine(nX1, nY1), nLine2 = GetLine(nX2, nY2);
		long long llAnswer = static_cast<long long>(nLine1 + nLine2 + 2) * (nLine2 - nLine1 + 1) / 2;
		llAnswer -= nY1 + nX2 + 1;
		cout << "Case " << nTestCaseLoop << ": " << llAnswer << endl;
	}

	return 0;
}