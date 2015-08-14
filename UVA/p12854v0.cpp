/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12854 - Automated Checking Machine                               */


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int ReadConnector(const string &roString) {
	stringstream oStream(roString);

	int nRet = 0, nN;

	oStream >> nN; nRet |= nN;
	oStream >> nN; nRet |= (nN << 1);
	oStream >> nN; nRet |= (nN << 2);
	oStream >> nN; nRet |= (nN << 3);
	oStream >> nN; nRet |= (nN << 4);

	return nRet;
}

int main() {
	string oLine;
	while (getline(cin, oLine)) {
		int nFirst = ReadConnector(oLine);
		getline(cin, oLine);
		int nSecond = ReadConnector(oLine);

		cout << ((nFirst ^ nSecond) == 0x1F ? 'Y' : 'N') << endl;
	}

	return 0;
}