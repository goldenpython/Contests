/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11926 - Multitasking                                             */


#include <iostream>
#include <vector>

using namespace std;

bool HasOverlap(vector<bool> &roVecBitmap, int nStart, int nEnd) {
	if (nEnd >= roVecBitmap.size())
		nEnd = static_cast<int>(roVecBitmap.size()) - 1;

	for ( ; nStart < nEnd; nStart++)
		if (roVecBitmap[nStart])
			return true;
		else
			roVecBitmap[nStart] = true;

	return false;
}

int main() {
	for (
		int nNoNonRepeatingTasks, nNoRepeatingTasks; 
		(cin >> nNoNonRepeatingTasks >> nNoRepeatingTasks), nNoNonRepeatingTasks || nNoRepeatingTasks; 

	) {
		const int MAX = 1000000;
		vector<bool> oVecbBitmap(MAX + 1, 0);
		bool bHasOverlap= false; 
		while (nNoNonRepeatingTasks--) {
			int nStart, nEnd;
			cin >> nStart >> nEnd;
			if (!bHasOverlap)
				bHasOverlap = HasOverlap(oVecbBitmap, nStart, nEnd);
		}

		while (nNoRepeatingTasks--) {
			int nStart, nEnd, nRepeatInterval;
			cin >> nStart >> nEnd >> nRepeatInterval;
			for (; !bHasOverlap && nStart <= MAX; nStart += nRepeatInterval, nEnd += nRepeatInterval)
				bHasOverlap = HasOverlap(oVecbBitmap, nStart, nEnd);
		}

		cout << (bHasOverlap ? "" : "NO ") << "CONFLICT" << endl;
	}

	return 0;
}