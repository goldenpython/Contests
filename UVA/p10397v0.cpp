/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10397 - Connect the Campus                                       */



#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;


/*************************************************************/

/*	UF class v1.0*/
class UF {
	public:
		UF(int nNumMaxNodes, int nNumNodes) {
			m_arrnFather = new int[nNumMaxNodes];
			ReInit(nNumNodes);
		}

		~UF() {
			delete m_arrnFather;
		}

		void ReInit(int nNumNodes) {
			m_nNumNodes = nNumNodes;
			for (int nLoop = 0; nLoop < nNumNodes; nLoop++)
				m_arrnFather[nLoop] = nLoop;
		}

		int FindRoot(int nNode) {
			while (nNode != m_arrnFather[nNode])
				nNode = m_arrnFather[nNode];

			return nNode;
		}

		bool SameComponent(int nNode1, int nNode2)  {
			return FindRoot(nNode1) == FindRoot(nNode2);
		}

		void Connect(int nNode1, int nNode2) {
			nNode1 = FindRoot(nNode1);
			nNode2 = FindRoot(nNode2);

			m_arrnFather[nNode1] = nNode2;
		}

	private:
		int m_nNumNodes;
		int *m_arrnFather;
};

/*************************************************************/

#define MAX_CITIES			(750 + 2)
#define MAX_EDGES			(MAX_CITIES * (MAX_CITIES - 1) / 2)
#define MAX_COORD			(10000 + 10)
#define MAX_COORD_POW2		(MAX_COORD * MAX_COORD)

typedef struct {
	int nPosX, nPosY;
	//bool bUsed;
} CITY;

typedef struct {
	int nDist;
	int nCity1, nCity2;
} EDGE;

bool compare(EDGE *poLHS, EDGE *poRHS) {
	return poLHS->nDist < poRHS->nDist;
}

EDGE g_arroEdges[MAX_EDGES];
EDGE *g_arrpoEdges[MAX_EDGES];

int main() {
	int nNoCities;
	CITY arroCities[MAX_CITIES];

	UF oUF(MAX_CITIES, MAX_CITIES);
	while (scanf("%d", &nNoCities) == 1 && nNoCities) {
		oUF.ReInit(nNoCities);

		for (int nLoop = 0; nLoop < nNoCities; nLoop++) {
			scanf("%d %d", &arroCities[nLoop].nPosX, &arroCities[nLoop].nPosY);
			//arroCities[nLoop].bUsed = false;
		}

		int nNoConnections, nNoConnectedComponents = nNoCities - 1;
		scanf("%d", &nNoConnections);
		for (int nLoop = 0; nLoop < nNoConnections; nLoop++) {
			int nCity1, nCity2;
			scanf("%d %d", &nCity1, &nCity2);
			nCity1--; nCity2--;
			//arroCities[nCity1].bUsed = arroCities[nCity2].bUsed = true;

			if (!oUF.SameComponent(nCity1, nCity2))
				oUF.Connect(nCity1, nCity2), nNoConnectedComponents--;
		}

		int nNoEdges = 0;
		for (int nLoop1 = 0; nLoop1 < nNoCities; nLoop1++)
			for (int nLoop2 = nLoop1 + 1; nLoop2 < nNoCities; nLoop2++)
				if (!oUF.SameComponent(nLoop1, nLoop2)) {
					g_arroEdges[nNoEdges].nDist = (arroCities[nLoop1].nPosX - arroCities[nLoop2].nPosX) * (arroCities[nLoop1].nPosX - arroCities[nLoop2].nPosX) + (arroCities[nLoop1].nPosY - arroCities[nLoop2].nPosY) * (arroCities[nLoop1].nPosY - arroCities[nLoop2].nPosY);
					g_arroEdges[nNoEdges].nCity1 = nLoop1;
					g_arroEdges[nNoEdges].nCity2 = nLoop2;
					g_arrpoEdges[nNoEdges] = &g_arroEdges[nNoEdges];
					nNoEdges++;
				}

		sort(&g_arrpoEdges[0], &g_arrpoEdges[nNoEdges], compare);

		int nLoop = 0;
		double nSol = 0;
		while (nNoConnectedComponents) {
			if (!oUF.SameComponent(g_arrpoEdges[nLoop]->nCity1, g_arrpoEdges[nLoop]->nCity2)) {
				oUF.Connect(g_arrpoEdges[nLoop]->nCity1, g_arrpoEdges[nLoop]->nCity2);
				nSol += sqrt((double)g_arrpoEdges[nLoop]->nDist);
				nNoConnectedComponents--;
			}
			nLoop++;
		}

		printf("%.2lf\n", nSol);
	}

	return 0;
}