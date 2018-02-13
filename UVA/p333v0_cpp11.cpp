/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 333 - Recognizing Good ISBNs                                     */


#include <iostream>
#include <string>

using namespace std;

int main() {
	
	for (string oLine; getline(cin, oLine); ) {
		const string oWhiteSpace(" \n\r\t");
		const int ISBN_NO_DIGITS = 10;

		size_t nFirstPos = oLine.find_first_not_of(oWhiteSpace);
		if (nFirstPos == string::npos)
			nFirstPos = 0;
		size_t nLastPos = oLine.find_last_not_of(oWhiteSpace);
		if (nLastPos == string::npos)
			nLastPos = oLine.size();
		oLine = oLine.substr(nFirstPos, nLastPos - nFirstPos + 1);
		
		int s1 = 0, s2 = 0, nNoDigits = 0;
		for (nLastPos -= nFirstPos, nFirstPos = 0; nFirstPos <= nLastPos && nNoDigits <= 10; nFirstPos++) {
			const char nCharacter = oLine[nFirstPos];
			if (nCharacter == '-')
				continue;

			int nDigit = -1;
			if (isdigit(nCharacter)) {
				nDigit = nCharacter - '0';
			} else if (nCharacter == 'X') {
				if (nNoDigits == ISBN_NO_DIGITS - 1)
					nDigit = 10;
				else
					break;
			} else {
				continue;
			}

			s1 += nDigit;
			s2 += s1;
			nNoDigits++;
		}

		bool bIsCorrect = !(s2 % 11) && nNoDigits == 10;
		cout << oLine << " is " << (bIsCorrect ? "correct." : "incorrect.") << endl;
	}

	return 0;
}