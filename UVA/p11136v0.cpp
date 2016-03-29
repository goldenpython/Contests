/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11136 - Hoax or what                                             */


#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
	for (int nNoDays; (cin >> nNoDays) && nNoDays; ) {
		multiset<int> oSetCurrentBills;

		long long llSol = 0;
		while (nNoDays--) {
			int nNoBills; 
			cin >> nNoBills; 
			while (nNoBills--) {
				int nCurrentBill;
				cin >> nCurrentBill;
				oSetCurrentBills.insert(oSetCurrentBills.end(), nCurrentBill);
			}

			llSol += *(oSetCurrentBills.begin());
			oSetCurrentBills.erase(oSetCurrentBills.begin());

			multiset<int>::iterator oIt = oSetCurrentBills.end();
			--oIt;	
			llSol -= *oIt;
			oSetCurrentBills.erase(oIt);
		}

		cout << abs(llSol) << endl;
	}

	return 0;
}