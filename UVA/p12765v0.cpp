/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12765 - Factorial Products                                       */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef double LOG_TYPE;
typedef std::vector<LOG_TYPE> LOG_CONTAINER_TYPE;

void Generate(LOG_CONTAINER_TYPE &roLogs, const int nNoLogs) {
	roLogs.push_back(0.0);
	for (int nLoop = 1; nLoop <= nNoLogs; nLoop++)
		roLogs.push_back(roLogs[nLoop - 1] + log(static_cast<LOG_CONTAINER_TYPE::value_type>(nLoop)));
}

LOG_TYPE ComputeFactProdLogFromLine(const int nNoNumbers, const LOG_CONTAINER_TYPE &roLogs) {
	LOG_TYPE tResult = 0;

	for (int nLoop = 0; nLoop < nNoNumbers; nLoop++) {
		int nNumber;
		cin >> nNumber;
		tResult += roLogs[nNumber];
	}

	return tResult;
}

int main() {
	const int MAX_FACTORIAL = 9;
	LOG_CONTAINER_TYPE oLogs;
	Generate(oLogs, MAX_FACTORIAL);

	for (int nN, nM; (cin >> nN >> nM), nN && nM; ) {
		 LOG_TYPE tRes1 = ComputeFactProdLogFromLine(nN, oLogs);
		 LOG_TYPE tRes2 = ComputeFactProdLogFromLine(nM, oLogs);
		 const LOG_TYPE EPS = 1E-5;
		 cout << (abs(abs(tRes1 - tRes2) < EPS) ? "YES" : "NO") << endl;
	}

	return 0;
}