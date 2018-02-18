/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1062 - Containers                                                */


#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	string oLine;
	for (int nCaseLoop = 1; (cin >> oLine), oLine != "end"; nCaseLoop++) {
		list<char> oListTopStacks;
		for (auto oIt = oLine.cbegin(); oIt != oLine.cend(); ++oIt) {
			auto cCharacter = *oIt;
			auto oItStack = find_if(
				oListTopStacks.begin(), 
				oListTopStacks.end(), 
				[cCharacter] (const char cCurrentTop) { return cCurrentTop >= cCharacter; }
			);

			if (oItStack != oListTopStacks.end())
				*oItStack = *oIt;
			else
				oListTopStacks.push_back(*oIt);
		}

		cout << "Case " << nCaseLoop << ": " << oListTopStacks.size() << endl;
	}

	return 0;
}