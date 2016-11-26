/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13135 - Homework                                                 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	const int MAX = 50000000;
	vector<int> oVecnAnswers;
	for (
		int nLoop = 0, nCurrentAnswer; 
		(nCurrentAnswer = (nLoop + 1) * (nLoop + 2) / 2) <= MAX; 
		nLoop++
	) {
			oVecnAnswers.push_back(nCurrentAnswer);
	}

	int nNoCases;
	for (cin >> nNoCases; nNoCases--; ) {
		int nQuery;
		cin >> nQuery;
		auto oIt = lower_bound(oVecnAnswers.cbegin(), oVecnAnswers.cend(), nQuery);
		if (oIt == oVecnAnswers.cend() || *oIt != nQuery)
			cout << "No solution" << endl;
		else
			cout << oIt - oVecnAnswers.cbegin() << endl;
	}

	return 0;
}