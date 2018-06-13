/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11069 - A Graph Problem                                          */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int MAX_NODES = 76;
	vector<int> oVecnCount(MAX_NODES + 1);
	oVecnCount[1] = oVecnCount[2] = oVecnCount[3] = 1;
	for (int nLoop = 4; nLoop <= MAX_NODES; nLoop++)
		oVecnCount[nLoop] = oVecnCount[nLoop - 2] + oVecnCount[nLoop - 3];

	for (int nNoNodes; cin >> nNoNodes; )
		cout << oVecnCount[nNoNodes - 1] + oVecnCount[nNoNodes] << endl;

	return 0;
}