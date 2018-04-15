/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11278 - One-Handed Typist                                        */


#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	const string oQWERTY = "`1234567890-=\\[];',./~!@#$%^&*()_+|{}:\"<>?AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	const string oDWORAK = "`123qjlmfp/[]\\;=k-vg'~!@#QJLMFP?{}|:+K_VG\"&7IiXx(9^6AaEeHhUuTtDdCcWwNnYyBb$4>.*8OoSs<,%5ZzRr)0";
	assert(oQWERTY.size() == oDWORAK.size());

	vector<char> oVecQWERTY2DWORAKMapping(256, '\0');
	iota(oVecQWERTY2DWORAKMapping.begin(), oVecQWERTY2DWORAKMapping.end(), 0);
	for (int nLoop = static_cast<int>(oQWERTY.size()) - 1; nLoop >= 0; nLoop--)
		oVecQWERTY2DWORAKMapping[oQWERTY[nLoop]] = oDWORAK[nLoop];

	string oLine;
	while (getline(cin, oLine)) {
		transform(oLine.cbegin(), oLine.cend(), oLine.begin(), [&oVecQWERTY2DWORAKMapping](char c) { return oVecQWERTY2DWORAKMapping[c]; });
		cout << oLine << endl;
	}

	return 0;
}