/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 576 - Haiku Review                                               */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int GetNoSyllables(const string::const_iterator &roItStart, const string::const_iterator &roItEnd) {
	int nNoSyllables = 0;
	bool bLastCharacterIsVowel = false;
	for_each(
		roItStart, 
		roItEnd,
		[&nNoSyllables, &bLastCharacterIsVowel](const char cChar) {
			if ((cChar == 'a' || cChar == 'e' || cChar == 'i' || cChar == 'o' || cChar == 'u' || cChar == 'y')) {
				if (!bLastCharacterIsVowel) {
					nNoSyllables++;
					bLastCharacterIsVowel = true;
				}
			} else {
				bLastCharacterIsVowel = false;
			}
		}
	);

	return nNoSyllables;
}

int main() {
	for (string oLine; getline(cin, oLine), oLine != "e/o/i"; ) {
		auto nFirstIndexSeparator = oLine.find_first_of('/');
		auto nNoSyllables = GetNoSyllables(oLine.cbegin(), oLine.cbegin() + nFirstIndexSeparator);
		if (nNoSyllables != 5) {
			cout << 1 << endl;
			continue;
		}

		auto nSecondIndexSeparator = oLine.find_last_of('/');
		nNoSyllables = GetNoSyllables(oLine.cbegin() + nFirstIndexSeparator, oLine.cbegin() + nSecondIndexSeparator);
		if (nNoSyllables != 7) {
			cout << 2 << endl;
			continue;
		}

		nNoSyllables = GetNoSyllables(oLine.cbegin() + nSecondIndexSeparator, oLine.cend());
		if (nNoSyllables != 5) {
			cout << 3 << endl;
			continue;
		}

		cout << 'Y' << endl;
	}

	return 0;
}