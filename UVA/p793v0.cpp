/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 793 - Network Connections                                        */




#include <stdio.h>
#include <string.h>
#include <stdlib.h>





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

int main() {
	const int MAX_LINE_LEN = 128;
	const int MAX_NODES = 1010;

	char szLine[MAX_LINE_LEN];

	UF oUF(MAX_NODES, 0);

	int nNoCases = atoi(gets(szLine));
	gets(szLine);

	for ( ; nNoCases; nNoCases--) {
		int arrnSol[2] = {0};
		int nNoComputers = atoi(gets(szLine));
		oUF.ReInit(nNoComputers + 1);
		while (gets(szLine) && *szLine) {
			char nC;
			int nNode1, nNode2; 
			sscanf(szLine, "%c %d %d", &nC, &nNode1, &nNode2);

			if (nC == 'c') {
				oUF.Connect(nNode1, nNode2);
			} else {
				arrnSol[oUF.SameComponent(nNode1, nNode2)]++;
			}
		}
		printf("%d,%d\n", arrnSol[1], arrnSol[0]);
		if (nNoCases > 1)
			printf("\n");
	}
	

	return 0;
}