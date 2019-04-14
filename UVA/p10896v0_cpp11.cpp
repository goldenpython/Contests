/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10896 - Known Plaintext Attack                                   */


#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

char GetCharDiff(char c1, char c2) {
	return (c1 - c2 + 26) % 26;
}

char GetKey(const string &roEncString, const string &roDecString) {
	if (roEncString.size() != roDecString.size())
		return -1;

	char nDiff = GetCharDiff(roEncString[0], roDecString[0]);
	for (int nLoop = static_cast<int>(roEncString.size() - 1); nLoop; nLoop--)
		if (GetCharDiff(roEncString[nLoop], roDecString[nLoop]) != nDiff)
			return -1;

	return 'a' + nDiff;
}

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoTestCases = stoi(oLine); nNoTestCases--; ) {
		string oEncSentence, oDecWord, oAnswer;
		getline(cin, oEncSentence); getline(cin, oDecWord);
		stringstream oStringStream(oEncSentence);
		for (string oEncWord; oStringStream >> oEncWord; ) {
			char c = GetKey(oEncWord, oDecWord);
			if (c >= 0)
				oAnswer += c;
		}

		sort(oAnswer.begin(), oAnswer.end());
		cout << oAnswer << endl;
	}

	return 0;
}