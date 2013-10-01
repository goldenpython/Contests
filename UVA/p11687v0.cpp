/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11687 - Digits                                                   */


#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
	string oLine;

	while (getline(cin, oLine), oLine != "END") {
		int nCnt, nNumber;
		if (oLine.size() < 5)
			nCnt = 0, nNumber = atoi(oLine.c_str());
		else
			nCnt = 1, nNumber = oLine.size();

		while (true) {
			char szLine[32];
			sprintf(szLine, "%d", nNumber);
			oLine = szLine;
			nCnt++;
			if (nNumber == oLine.size())
				break;
			nNumber = oLine.size();
		}

		cout << nCnt << endl;
	}

	return 0;
}