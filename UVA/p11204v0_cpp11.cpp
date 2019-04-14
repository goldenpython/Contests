/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11204 - Musical instruments                                      */


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nNoInstruments, nNoStudents;
		cin >> nNoInstruments >> nNoStudents;
		vector<int> oVecnNoStudentsWithInstrumentAsFirstChoice(nNoInstruments);
		while (nNoStudents--) {
			for (int nLoopInstrument = 0; nLoopInstrument < nNoInstruments; nLoopInstrument++) {
				int nValue;
				cin >> nValue;
				if (nValue == 1)
					oVecnNoStudentsWithInstrumentAsFirstChoice[nLoopInstrument]++;
			}
		}

		auto nRes = accumulate(
			oVecnNoStudentsWithInstrumentAsFirstChoice.cbegin(), 
			oVecnNoStudentsWithInstrumentAsFirstChoice.cend(), 
			1, 
			[] (int nProduct, int nCurrentElement) { return nProduct * max(nCurrentElement, 1); }
		);

		cout << nRes << endl;
	}
	return 0;
}