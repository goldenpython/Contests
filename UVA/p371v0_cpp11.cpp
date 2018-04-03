/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 371 - Ackermann Functions                                        */


#include <iostream>
#include <unordered_map>

using namespace std;

int GetAckermannLen(unsigned int nN, unordered_map<unsigned int, unsigned int> &roAckermannLen) {
	auto oIt = roAckermannLen.find(nN);
	if (oIt != roAckermannLen.end())
		return oIt->second;

	return roAckermannLen[nN] = GetAckermannLen(nN % 2 ? 3 * nN + 1 : nN / 2, roAckermannLen) + 1;
}

int main() {
	int nL, nH;
	unordered_map<unsigned int, unsigned int> oMapAckermannLen;
	oMapAckermannLen[1] = 0;

	while ((cin >> nL >> nH), nL && nH) {
		if (nL > nH)
			swap(nL, nH);

		int nMaxPos = nL;
		for (int nLoop = nL; nLoop <= nH; nLoop++) {
			int nCurrent = nLoop;
			if ((oMapAckermannLen[nCurrent] = GetAckermannLen(nCurrent, oMapAckermannLen)) > oMapAckermannLen[nMaxPos])
				nMaxPos = nCurrent;
		}

		int nMaxLen = oMapAckermannLen[nMaxPos];

		if (oMapAckermannLen[nMaxPos] < 3 && nL <= 1 && nH >= 1)
			nMaxLen = 3;

		cout << "Between " << nL << " and " << nH << ", " << nMaxPos << " generates the longest sequence of " << nMaxLen << " values." << endl;
	}

	return 0;
}