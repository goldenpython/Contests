/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10298 - Power Strings                                            */


#include <iostream>
#include <string>

using namespace std;

int main() {
	string oLine;
	while (getline(cin, oLine), oLine != ".") {
		size_t nSol = 1;
		for (size_t nLoopSize = oLine.size() / 2; nLoopSize >= 1; nLoopSize--)
			if (!(oLine.size() % nLoopSize)) {
				size_t nCount = oLine.size() / nLoopSize;
				bool bIsValid = true;
				for (size_t nIndex = 1; nIndex < nCount; nIndex++)
					if (!equal(oLine.cbegin(), oLine.cbegin() + nLoopSize, oLine.cbegin() + nIndex * nLoopSize)) {
						bIsValid = false;
						break;
					}

				if (bIsValid)
					nSol = nCount;
			}

		cout << nSol << endl;
	}
}