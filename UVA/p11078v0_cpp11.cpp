/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11078 - Open Credit System                                       */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		const int MIN_SCORE = -(150000 + 1);
		int nNoStudents, nCurrentMax = MIN_SCORE, nCurrentMaxDiff = MIN_SCORE;
		for (cin >> nNoStudents; nNoStudents--; ) {
			int nCurrentStudentScore;
			cin >> nCurrentStudentScore;

			auto nCurrentDiff = nCurrentMax - nCurrentStudentScore;
			if (nCurrentMaxDiff < nCurrentDiff)
				nCurrentMaxDiff = nCurrentDiff;

			if (nCurrentStudentScore > nCurrentMax)
				nCurrentMax = nCurrentStudentScore;
		}

		cout << nCurrentMaxDiff << endl;
	}

	return 0;
}