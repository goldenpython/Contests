/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10026 - Shoemaker's Problem                                      */


#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		struct JOB {
			int nTime, nFine, nIndex;
			JOB(int nTime, int nFine, int nIndex) : nTime(nTime), nFine(nFine), nIndex(nIndex) {}
		};

		int nNoJobs;
		cin >> nNoJobs;

		vector<unique_ptr<JOB>> oVecJobs;
		oVecJobs.reserve(nNoJobs);

		for (int nJobLoop = 0; nJobLoop < nNoJobs; ) {
			int nTime, nFine;
			cin >> nTime >> nFine;
			oVecJobs.push_back(unique_ptr<JOB>(new JOB(nTime, nFine, ++nJobLoop)));
		}

		sort(
			oVecJobs.begin(), 
			oVecJobs.end(), 
			[] (const unique_ptr<JOB> &roLHS, const unique_ptr<JOB> &roRHS) { return roLHS->nTime * roRHS->nFine < roRHS->nTime * roLHS->nFine; }
		);


		cout << (*oVecJobs.cbegin())->nIndex;
		for_each(oVecJobs.cbegin() + 1, oVecJobs.cend(), [] (const unique_ptr<JOB> &roJOB) { cout << " " << roJOB->nIndex; });

		cout << endl;
		if (nNoTestCases)
			cout << endl;
	}

	return 0;
}