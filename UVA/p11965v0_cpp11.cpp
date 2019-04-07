/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11965 - Extra Spaces                                             */


#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))


#include <iostream>
#include <string>

using namespace std;

int ReadLineContainingInt() {
	string oLine;
	getline(cin, oLine);
	return stoi(oLine);
}

string RemoveExtraSpaces(const string &roString) {
	string oTrimmedString;
	bool bPrevCharacterWasSpace = false;
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		for (auto cCharacter : roString) {
#else
		for (auto oIt = roString.cbegin(); oIt != roString.cend(); ++oIt) {
			auto cCharacter = *oIt;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		if (!bPrevCharacterWasSpace || cCharacter != ' ')
			oTrimmedString.push_back(cCharacter);

		bPrevCharacterWasSpace = (cCharacter == ' ');
	}

	return oTrimmedString;
}

int main() {
	for (int nNoTestCases = ReadLineContainingInt(), nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		cout << "Case " << nCaseLoop << ":" << endl;

		for (int nNoLinesInCase = ReadLineContainingInt(); nNoLinesInCase--; ) {
			string oLine;
			getline(cin, oLine);
			cout << RemoveExtraSpaces(oLine) << endl;
		}

		if (nCaseLoop < nNoTestCases)
			cout << endl;
	}

	return 0;
}