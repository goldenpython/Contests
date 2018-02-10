/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 850 - Crypt Kicker II                                            */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsReference(const string &roString, vector<char> &roVecEncoding) {
	static const string oReference("the quick brown fox jumps over the lazy dog");
	if (roString.size() != oReference.size())
		return false;

	vector<char> oVecEncoding(256, 0);
	for (
		auto oItString = roString.cbegin(), oItReference = oReference.cbegin();
		oItString != roString.cend();
		++oItString, ++oItReference
	) {
		if (isspace(*oItString) && isspace(*oItReference))
			continue;

		if (!islower(*oItString) || !islower(*oItReference))
			return false;

		if (oVecEncoding[*oItString] && oVecEncoding[*oItString] != *oItReference)
			return false;

		oVecEncoding[*oItString] = *oItReference;
	}

	oVecEncoding[' '] = ' ';
	roVecEncoding.swap(oVecEncoding);

	return true;
}

void DecodeString(string &roString, vector<char> &roVecEncoding) {
	transform(
		roString.cbegin(), 
		roString.cend(), 
		roString.begin(), 
		[&roVecEncoding] (char c) { return roVecEncoding[c]; }
	);
}

int main() {
	string oLine;
	getline(cin, oLine);
	int nNoTestCases = stoi(oLine);
	getline(cin, oLine);
	for (; nNoTestCases--; ) {
		vector<string> oVecEncodedStrings;
		vector<char> oVecEncoding;
		bool bFoundStandardEncryptedText = false;
		while (getline(cin, oLine) && oLine.size() > 0) {
			if (!bFoundStandardEncryptedText && IsReference(oLine, oVecEncoding))
				bFoundStandardEncryptedText = true;

			oVecEncodedStrings.emplace_back(oLine);
		}

		if (bFoundStandardEncryptedText) {
			for (auto &roEncodedString : oVecEncodedStrings) {
				DecodeString(roEncodedString, oVecEncoding);
				cout << roEncodedString << endl;
			}
		} else {
			cout << "No solution." << endl;
		}

		if (nNoTestCases)
			cout << endl;
	}

	return 0;
}