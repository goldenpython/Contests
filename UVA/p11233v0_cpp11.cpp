/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11233 - Deli Deli                                                */


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int nL, nN;
	cin >> nL >> nN;
	unordered_map<string, string> oMapPlural;
	while (nL--) {
		string oWord, oPlural;
		cin >> oWord >> oPlural;
		oMapPlural.emplace(make_pair(move(oWord), move(oPlural)));
	}

	while (nN--) {
		string oWord;
		cin >> oWord;
		auto oIt = oMapPlural.find(oWord);
		if (oIt != oMapPlural.cend()) {
			cout << oIt->second << endl;
		} else {
			int nLen = oWord.size();

			do {
				if (
					nLen >= 2 && 
					oWord[nLen - 1] == 'y' && 
					oWord[nLen - 2] != 'a' && oWord[nLen - 2] != 'e' && oWord[nLen - 2] != 'i' && oWord[nLen - 2] != 'o' && oWord[nLen - 2] != 'u'
				) {
					oWord = oWord.substr(0, nLen - 1) + "ies";
					break;
				}

				if (oWord[nLen - 1] == 'o' || oWord[nLen - 1] == 's' || oWord[nLen - 1] == 'x' || oWord.rfind("ch") == nLen - 2 || oWord.rfind("sh") == nLen - 2) {
					oWord += "es";
					break;
				}

				oWord += "s";
			} while (false);


			cout << oWord << endl;
		}
	}

	return 0;
}