/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1585 - Score                                                     */



#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoTestCases = atoi(oLine.c_str()); nNoTestCases--;) {
		getline(cin, oLine);
		int nSol = 0, nCurrent = 0;
		for (string::iterator oIt = oLine.begin(); oIt != oLine.end(); oIt++)
			if (*oIt == 'O')
				nSol += ++nCurrent;
			else
				nCurrent = 0;

		cout << nSol << endl;
	}

	return 0;
}