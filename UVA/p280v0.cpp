/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 280 - Vertex                                                     */



#include <stdio.h>
#include <string.h>

#define MAX_NODES	120

int main() {
	int nNoNodes;
	int g_arr2nAdj[MAX_NODES][MAX_NODES];

	while (scanf("%d", &nNoNodes), nNoNodes) {
		for (int nLoop = 0; nLoop < nNoNodes; nLoop++)
			g_arr2nAdj[nLoop][0] = 0;

		int nNodeFrom;
		while (scanf("%d", &nNodeFrom), nNodeFrom) {
			nNodeFrom--;

			int nNodeTo;
			while (scanf("%d", &nNodeTo), nNodeTo)
				g_arr2nAdj[nNodeFrom][++g_arr2nAdj[nNodeFrom][0]] = nNodeTo - 1;
		}

		int nNoTestCases;
		scanf("%d", &nNoTestCases);
		{
			int nTestNode;
			for (int nLoop = 0; nLoop < nNoTestCases; nLoop++) {
				scanf("%d", &nTestNode); nTestNode--;

				bool arrbVisited[MAX_NODES];
				int nQ1, nQ2, nNoVisitedNodes = 0, arrnQ[MAX_NODES];
				memset(arrbVisited, 0, sizeof(bool) * nNoNodes);
				arrnQ[nQ1 = nQ2 = 0] = nTestNode;
				while (nQ1 <= nQ2) {
					int nCurrentNode = arrnQ[nQ1++];
					for (int nLoopNeighbours = 1; nLoopNeighbours <= g_arr2nAdj[nCurrentNode][0]; nLoopNeighbours++)
						if (!arrbVisited[g_arr2nAdj[nCurrentNode][nLoopNeighbours]]) {
							arrbVisited[g_arr2nAdj[nCurrentNode][nLoopNeighbours]] = true;
							arrnQ[++nQ2] = g_arr2nAdj[nCurrentNode][nLoopNeighbours];
							nNoVisitedNodes++;
						}
				}

				printf("%d", nNoNodes - nNoVisitedNodes);
				for (int nLoop = 0; nLoop < nNoNodes; nLoop++)
					if (!arrbVisited[nLoop])
						printf(" %d", nLoop + 1);
				printf("\n");
			}
		}
	}

	return 0;
}