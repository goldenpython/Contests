/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10369 - Arctic Network                                           */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <algorithm>

#if !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)
	#include <limits.h>
	#define gets(a) gets_s(a, INT_MAX)
#endif // !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)

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


const int MAX_VERTICES = 510;
const int MAX_EDGES = MAX_VERTICES * (MAX_VERTICES - 1) / 2;

struct EDGE {
	int nNode1, nNode2;
	int nCost;
};

struct POINT {
	int X, Y;
};

bool EdgeComparator(EDGE *poEdge1, EDGE *poEdge2) { 
	return poEdge1->nCost < poEdge2->nCost; 
}

POINT m_arroPoints[MAX_VERTICES];
EDGE m_arroEdges[MAX_EDGES];
EDGE* m_arrpoEdges[MAX_EDGES];


int main() {
	char szLine[64];
	
	UF oUF(MAX_VERTICES, 0);

	for (int nNoCases = atoi(gets(szLine)); nNoCases; nNoCases--) {
		int nS, nN;
		gets(szLine);
		sscanf(szLine, "%d %d", &nS, &nN);

		for (int nLoop = 0; nLoop < nN; nLoop++) {
			gets(szLine);
			sscanf(szLine, "%d %d", &m_arroPoints[nLoop].X, &m_arroPoints[nLoop].Y);
		}

		int nIndex = 0;
		for (int nLoop1 = 0; nLoop1 < nN; nLoop1++) {
			for (int nLoop2 = nLoop1 + 1; nLoop2 < nN; nLoop2++) {
				m_arrpoEdges[nIndex] = &m_arroEdges[nIndex];

				m_arrpoEdges[nIndex]->nNode1 = nLoop1;
				m_arrpoEdges[nIndex]->nNode2 = nLoop2;
				m_arrpoEdges[nIndex]->nCost = (m_arroPoints[nLoop1].X - m_arroPoints[nLoop2].X) * (m_arroPoints[nLoop1].X - m_arroPoints[nLoop2].X) + (m_arroPoints[nLoop1].Y - m_arroPoints[nLoop2].Y) * (m_arroPoints[nLoop1].Y - m_arroPoints[nLoop2].Y);

				nIndex++;
			}
		}

		oUF.ReInit(nN);
		sort(m_arrpoEdges, m_arrpoEdges + nIndex, EdgeComparator);

		nIndex = 0;
		while (nS < nN) {
			while (oUF.SameComponent(m_arrpoEdges[nIndex]->nNode1, m_arrpoEdges[nIndex]->nNode2))
				nIndex++;

			oUF.Connect(m_arrpoEdges[nIndex]->nNode1, m_arrpoEdges[nIndex]->nNode2);
			nS++;
		}

		printf("%.2lf\n", sqrt((double)m_arrpoEdges[nIndex]->nCost));
	}

	return 0;
}