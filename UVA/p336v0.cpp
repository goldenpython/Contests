/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 336 - A Node Too Far                                             */



#include <stdio.h>
#include <map>

using namespace std;

int main() {
	const int MAX_NODES = 128;

	int nNoEdges, nCaseNumber = 0;

	while (scanf("%d", &nNoEdges), nNoEdges) {
		map<int, int> oMapVertex;
		int arrnNeighboursListSize[MAX_NODES] = {0};
		int arrnNeighboursList[MAX_NODES][MAX_NODES];

		for (int nEdgeLoop = 0; nEdgeLoop < nNoEdges; nEdgeLoop++) {
			int nVertex1, nVertex2;
			scanf("%d %d", &nVertex1, &nVertex2);

			int nVertexIndex1 = oMapVertex[nVertex1];
			if (!nVertexIndex1)
				nVertexIndex1 = oMapVertex[nVertex1] = oMapVertex.size();
			int nVertexIndex2 = oMapVertex[nVertex2];
			if (!nVertexIndex2)
				nVertexIndex2 = oMapVertex[nVertex2] = oMapVertex.size();

			arrnNeighboursList[nVertexIndex1][arrnNeighboursListSize[nVertexIndex1]++] = nVertexIndex2;
			arrnNeighboursList[nVertexIndex2][arrnNeighboursListSize[nVertexIndex2]++] = nVertexIndex1;
		}

		int nStartNode, nTTL, nNoVertices = oMapVertex.size();
		while (scanf("%d %d", &nStartNode, &nTTL), nStartNode || nTTL) {
			int nStartNodeIndex = oMapVertex[nStartNode];

			int nQHead, nQTail;
			bool arrbUsed[MAX_NODES] = {false};
			int arrnQueue[MAX_NODES];
			int arrnTTL[MAX_NODES];

			nQHead = nQTail = 0;
			arrbUsed[nStartNodeIndex] = true;
			arrnQueue[nQTail] = nStartNodeIndex;
			arrnTTL[nQTail] = nTTL;

			while(nQHead <= nQTail) {
				int nCurrentNode = arrnQueue[nQHead];
				for (int nNodeLoop = 0; nNodeLoop < arrnNeighboursListSize[nCurrentNode]; nNodeLoop++) {
					int nNode = arrnNeighboursList[nCurrentNode][nNodeLoop];
					if (!arrbUsed[nNode] && arrnTTL[nQHead] > 0) {
						arrbUsed[nNode] = true;
						arrnQueue[++nQTail] = nNode;
						arrnTTL[nQTail] = arrnTTL[nQHead] - 1;
					}
				}
				nQHead++;
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++nCaseNumber, nNoVertices - nQHead, nStartNode, nTTL);

		}
	};

	return 0;
}