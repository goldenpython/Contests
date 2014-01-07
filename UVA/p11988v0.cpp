/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11988 - Broken Keyboard (a.k.a. Beiju Text)                      */


#include <list>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string oLine;
	while (getline(cin, oLine)) {
		list<char> oSol;
		list<char>::iterator oCurrentPos = oSol.begin();
		for (string::iterator oIt = oLine.begin(); oIt != oLine.end(); oIt++) {
			switch(*oIt) {
				case '[':
					oCurrentPos = oSol.begin();
					break;
				case ']':
					oCurrentPos = oSol.end();
					break;
				default:
					oSol.insert(oCurrentPos, *oIt);
			}
		}

		for (oCurrentPos = oSol.begin(); oCurrentPos != oSol.end(); oCurrentPos++)
			cout << *oCurrentPos;
		cout << endl;
	}
}