/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11080 - Place the Guards                                         */



#include <iostream>
#include <string.h>

using namespace std;

int main() {
	const int MAX_NODES = 202;

	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nV, nE;
		cin >> nV >> nE;

		int arr2nGraph[MAX_NODES][MAX_NODES];
		int arr2nState[MAX_NODES];

		for (int nLoop = 0; nLoop < nV; nLoop++)
			arr2nGraph[nLoop][0] = 0;
		memset(arr2nState, 0, sizeof(int) * nV);

		for (int nLoop = 0; nLoop < nE; nLoop++) {
			int nNode1, nNode2;
			cin >> nNode1 >> nNode2;

			arr2nGraph[nNode1][++arr2nGraph[nNode1][0]] = nNode2;
			arr2nGraph[nNode2][++arr2nGraph[nNode2][0]] = nNode1;
		}

		bool bHasSol = true;
		int nSol = 0;

		for (int nNodeStart = 0; nNodeStart < nV && bHasSol; nNodeStart++)
			if (!arr2nState[nNodeStart]) {
				int arrnCompCount[3] = {0};
				arrnCompCount[arr2nState[nNodeStart] = 1]++;
				int nQHead, nQTail, arrnQueue[MAX_NODES];
				for (arrnQueue[nQHead = nQTail = 0] = nNodeStart; nQHead <= nQTail; nQHead++) {
					int nNodeCurrent = arrnQueue[nQHead];
					for (int nLoop = 1; nLoop <= arr2nGraph[nNodeCurrent][0]; nLoop++) {
						int nNodeNext = arr2nGraph[nNodeCurrent][nLoop];
						if (!arr2nState[nNodeNext]) {
							arrnCompCount[arr2nState[nNodeNext] = 3 - arr2nState[nNodeCurrent]]++;
							arrnQueue[++nQTail] = nNodeNext;
						} else if (arr2nState[nNodeCurrent] == arr2nState[nNodeNext]) {
							bHasSol = false;
							nQHead = nQTail;
							break;
						}
					}
				}


				nSol += !arrnCompCount[2] ? arrnCompCount[1] : (arrnCompCount[1] < arrnCompCount[2] ? arrnCompCount[1] : arrnCompCount[2]);
			}

			cout << (bHasSol ? nSol : -1) << endl;
	}

	return 0;
}