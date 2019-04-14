/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 641 - Do the Untwist                                             */


/*
	ciphercode[i] = (plaincode[ki mod n] - i) mod 28	==>
	(ciphercode[i] + i) mod 28 = (plaincode[ki mod n]) mod 28
*/

#include <iostream>
#include <string>

using namespace std;

inline int CharToIntCode(char c) {
	if (c == '_')
		return 0;
	else if (c == '.')
		return 27;
	else
		return c - 'a' + 1;
}

inline char IntCodeToChar(int nN) {
	if (nN == 0)
		return '_';
	else if (nN == 27)
		return '.';
	else
		return 'a' + nN - 1;
}

int main() {
	for (int nK; (cin >> nK), nK; ) {
		string oCiphertext;
		cin >> oCiphertext;
		string oPlainText(oCiphertext);

		for (int nIndex = 0, nLen = static_cast<int>(oCiphertext.size()); nIndex < nLen; nIndex++)
			oPlainText[(nK * nIndex) % nLen] = IntCodeToChar((CharToIntCode(oCiphertext[nIndex]) + nIndex) % 28);

		cout << oPlainText << endl;
	}
	return 0;
}