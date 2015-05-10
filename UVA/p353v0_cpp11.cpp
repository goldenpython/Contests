/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 353 - Pesky Palindromes                                          */


#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool IsPalindrome(string &oString) {
	for (string::iterator oItBegin = oString.begin(), oItEnd = oString.end() - 1; oItBegin < oItEnd; oItBegin++, oItEnd--)
		if (*oItBegin != *oItEnd)
			return false;
	return true;
}

int main() {

	for (string oLine; getline(cin, oLine); ) {
		unordered_set<string> oSetPalindromes;

		for (int nLoop = 0; nLoop < oLine.size(); nLoop++) {
			for (int nSize = 1; nSize <= oLine.size() - nLoop; nSize++) {
				string oString = oLine.substr(nLoop, nSize);
				if (IsPalindrome(oString))
					oSetPalindromes.insert(oString);
			}
		}

		cout << "The string '" << oLine << "' contains " << oSetPalindromes.size() << " palindromes." << endl; 
	}

	return 0;
}