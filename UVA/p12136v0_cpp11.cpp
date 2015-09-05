/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12136 - Schedule of a Married Man                                */


#include <iostream>
#include <string>

using namespace std;

int ReadTime(string::const_iterator &roIt) {
	int nH = ((roIt[0] - '0') * 10 + roIt[1] - '0');
	int nM = ((roIt[3] - '0') * 10 + roIt[4] - '0');
	return nH * 60 + nM;
}

void ReadTimes(const string &roLine, int &rnTime1, int &rnTime2) {
	auto oIt = roLine.begin();
	rnTime1 = ReadTime(oIt);
	oIt += 5;
	while (*oIt == ' ')
		oIt++;
	rnTime2 = ReadTime(oIt);
}

int main() {
	int nNoTestCases;
	string oLine;
	getline(cin, oLine);
	nNoTestCases = atoi(oLine.c_str());

	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		getline(cin, oLine);
		int nTW1, nTW2;
		ReadTimes(oLine, nTW1, nTW2);

		getline(cin, oLine);
		int nTM1, nTM2;
		ReadTimes(oLine, nTM1, nTM2);

		bool bNoMeeting = nTM1 >= nTW1 && nTM1 <= nTW2 || nTM2 >= nTW1 && nTM2 <= nTW2;
		cout << "Case " << nCaseLoop << ": " << (bNoMeeting ? "Mrs Meeting" : "Hits Meeting") << endl;
	}

	return 0;
}