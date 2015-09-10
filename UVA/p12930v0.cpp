/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12930 - Bigger or Smaller                                        */




#include <iostream>
#include <string>

using namespace std;

void ParseInt(const string &roString, string &roInt, string &roFrac, int &rnSign) {
	size_t nIndex = 0;
	rnSign = 1;
	if (roString[nIndex] == '+')
		nIndex++;
	else if (roString[nIndex] == '-')
		rnSign = -1, nIndex++;

	size_t nDotPos = roString.find_first_of('.');
	roInt = string(rnSign > 0 ? "2" : "1") + roString.substr(nIndex, nDotPos - nIndex);
	roFrac = roString.substr(nDotPos + 1, roString.size() - nDotPos);
	roFrac = roFrac.erase(roFrac.find_last_not_of('0') + 1);
}

int main() {
	string oLine;
	int nCase = 1;
	while (getline(cin, oLine)) {
		const string oRightChars("-+0123456789.");;

		size_t nNumber1Start = oLine.find_first_of(oRightChars);
		size_t nNumber1End = oLine.find_first_not_of(oRightChars, nNumber1Start);
		string oInt1, oFrac1;
		int nSign1;
		ParseInt(oLine.substr(nNumber1Start, nNumber1End - nNumber1Start), oInt1, oFrac1, nSign1);

		size_t nNumber2Start = oLine.find_first_of(oRightChars, nNumber1End);
		size_t nNumber2End = oLine.find_last_not_of(oRightChars, nNumber2Start);
		string oInt2, oFrac2;
		int nSign2;
		ParseInt(oLine.substr(nNumber2Start, nNumber2End - nNumber2Start), oInt2, oFrac2, nSign2);

		cout << "Case " << nCase++ << ": ";
		int nComp = oInt1.compare(oInt2);
		if (nComp < 0)
			cout << "Smaller" << endl;
		else if (nComp > 0)
			cout << "Bigger" << endl;
		else {
			nComp = oFrac1.compare(oFrac2);
			if (nComp < 0)
				cout << "Smaller" << endl;
			else if (nComp > 0)
				cout << "Bigger" << endl;
			else 
				cout << "Same" << endl;
		}
	}

	return 0;
}