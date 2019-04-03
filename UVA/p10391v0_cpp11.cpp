/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10391 - Compound Words                                           */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<string> oVecStrings;
	for (string oString; cin >> oString; )
		oVecStrings.push_back(std::move(oString));
	
	for (auto &roString : oVecStrings)
		for(auto oIt = roString.cbegin() + 1; oIt != roString.cend(); ++oIt)
			if (
				binary_search(oVecStrings.cbegin(), oVecStrings.cend(), string(roString.cbegin(), oIt)) &&
				binary_search(oVecStrings.cbegin(), oVecStrings.cend(), string(oIt, roString.cend())) 
			) {
				cout << roString << endl;
				break;
			}
	

	return 0;
}
