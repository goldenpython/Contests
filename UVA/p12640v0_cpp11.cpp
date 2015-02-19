/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12646 - Zero or One                                              */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
	 
template <typename T>
static istream& operator >> (istream &roStream, vector<T> &roVector) {

	while (!roStream.eof())  {
		T oElem;
		roStream >> oElem;
		roVector.push_back(oElem);
	}

	return roStream;
}

int main() {

	string oLine;

	while (getline(cin, oLine)) {
		stringstream oStream(oLine);

		int nMaxSum = 0, nCurrentSum = 0, nNumber;
		while (oStream >> nNumber) {
			nCurrentSum += nNumber;
			if (nCurrentSum > nMaxSum)
				nMaxSum = nCurrentSum;
			else if (nCurrentSum < 0)
				nCurrentSum = 0;
		}

		cout << nMaxSum << endl;
	}

	return 0;
}