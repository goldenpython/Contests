/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12195 - Jingle Composing                                         */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> oVecNoteDuration(256);
	oVecNoteDuration['W'] = 64 / 1;
	oVecNoteDuration['H'] = 64 / 2;
	oVecNoteDuration['Q'] = 64 / 4;
	oVecNoteDuration['E'] = 64 / 8;
	oVecNoteDuration['S'] = 64 / 16;
	oVecNoteDuration['T'] = 64 / 32;
	oVecNoteDuration['X'] = 64 / 64;

	string oLine;
	while (getline(cin, oLine), oLine != "*") {
		int nSol = 0;
		for (size_t nPosBegin = oLine.find('/'); nPosBegin != string::npos; ) {
			size_t nPosEnd = oLine.find('/', nPosBegin + 1);
			if (nPosEnd == string::npos)
				break;

			int nSum = 0;
			for (size_t nLoop = nPosBegin + 1; nLoop < nPosEnd && nSum <= 64; nLoop++)
				nSum += oVecNoteDuration[oLine[nLoop]];

			if (nSum == 64)
				nSol++;

			nPosBegin = nPosEnd;
		}

		cout << nSol << endl;
	}

	return 0;
}