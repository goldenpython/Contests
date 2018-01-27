/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12356 - Army Buddies                                             */


#include <iostream>
#include <list>
#include <vector>

using namespace std;

void Insert(int nNumber, list<int> &roList,  vector<list<int>::iterator> &roVecPos) {
	auto oIt = roList.insert(roList.end(), nNumber);
	roVecPos.insert(roVecPos.end(), oIt);
}

void Print(int nValue) {
	if (nValue > 0)
		cout << nValue;
	else
		cout << '*';
}

int main() {
	for (int nB, nS; (cin >> nB >> nS) && nB && nS; ) {
		list<int> oList;
		vector<list<int>::iterator> oVecPos;
		
		Insert(-1, oList, oVecPos);
		for (int nLoop = 1; nLoop <= nB; nLoop++)
			Insert(nLoop, oList, oVecPos);
		Insert(-2, oList, oVecPos);

		for (int nL, nR; nS--; ) {
			cin >> nL >> nR;
			auto oIt = oList.erase(oVecPos[nL], std::next(oVecPos[nR], 1));

			Print(*prev(oIt));
			cout << " ";
			Print(*oIt);
			cout << endl;
		}

		cout << "-" << endl;
	}
	return 0;
}