/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12592 - Slogan Learning of Princess                              */


#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	stringstream oStringStream(oLine);
	int nN;
	oStringStream >> nN;
	unordered_map<string, string> oMap;
	for (int nLoop = 0; nLoop < nN; nLoop++) {
		string s1, s2;
		getline(cin, s1); 
		getline(cin, s2);
		oMap[s1] = s2;
	}

	int nQ;
	getline(cin, oLine);
	oStringStream = stringstream(oLine);
	oStringStream >> nQ;
	for (int nLoop = 0; nLoop < nQ; nLoop++) {
		getline(cin, oLine);
		cout << oMap[oLine] << endl;
	}

	return 0;
}