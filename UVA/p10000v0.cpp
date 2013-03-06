/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10000 - Longest Paths                                            */



#include <stdio.h>


int main() {
	const int MAX_NODES = 102;

	for (int nCaseLoop = 1; ; nCaseLoop++) {
		int nNoNodes;
		if (scanf("%d", &nNoNodes) != 1 || !nNoNodes)
			break;

		int nStartNode;
		scanf("%d", &nStartNode);

		int nNoEdges = 0;
		int arrnEdges[MAX_NODES * (MAX_NODES - 1) / 2 * 2];

		int nNode1, nNode2;
		while (scanf("%d %d", &nNode1, &nNode2), nNode1 && nNode2) {
			arrnEdges[nNoEdges++] = nNode1;
			arrnEdges[nNoEdges++] = nNode2;
		}
	
		int arrnDist[MAX_NODES];
		for (int nNodeLoop = 1; nNodeLoop <= nNoNodes; nNodeLoop++)
			arrnDist[nNodeLoop] = 0xFF;
		arrnDist[nStartNode] = 0;

		bool bChange = true;
		while (bChange) {
			bChange = false;
			for (int nEdgeLoop = 0; nEdgeLoop < nNoEdges; nEdgeLoop += 2) {
				if (arrnDist[arrnEdges[nEdgeLoop + 1]] > arrnDist[arrnEdges[nEdgeLoop]] - 1) {
					arrnDist[arrnEdges[nEdgeLoop + 1]] = arrnDist[arrnEdges[nEdgeLoop]] - 1;
					bChange = true;
				}
			}
		}

		int nMinIndex = nStartNode;
		for (int nNodeLoop = 1; nNodeLoop <= nNoNodes; nNodeLoop++) {
			if (arrnDist[nNodeLoop] < arrnDist[nMinIndex])
				nMinIndex = nNodeLoop;
		}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", nCaseLoop, nStartNode, -arrnDist[nMinIndex], nMinIndex);
	}

	return 0;
}