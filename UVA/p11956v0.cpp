/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11956 - Brainfuck                                                */


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
	int nNoCases;
	string oLine;

	getline(cin, oLine); nNoCases = atoi(oLine.c_str());
	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		vector<unsigned char> oMem(100);
		int nCurrentPos = 0;
		
		getline(cin, oLine);
		for (string::iterator oIt = oLine.begin(); oIt != oLine.end(); oIt++) {
			switch (*oIt) {
				case '<':
					nCurrentPos = (nCurrentPos - 1 + oMem.size()) % oMem.size();
					break;
				case '>':
					nCurrentPos = (nCurrentPos + 1) % oMem.size();
					break;
				case '+':
					oMem[nCurrentPos]++;
					break;
				case '-':
					oMem[nCurrentPos]--;
					break;
			}
		}

		cout << "Case " << dec << nCaseLoop << ":";
		for (vector<unsigned char>::iterator oIt = oMem.begin(); oIt != oMem.end(); oIt++)
			cout << " " << hex << setfill('0') << setw(2) << uppercase << (*oIt & 0xFF);
		cout << endl;
	}

	return 0;
}
