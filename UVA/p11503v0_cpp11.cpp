/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11503 - Virtual Friends                                          */


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*************************************************************/

#define USE_WEIGHTED_QU
#define USE_PATH_COMPRESSION

/*	UF class v2.1	*/
class UF {
	public:
		void ReInit(int nNoNodes) {
			m_oFather.resize(nNoNodes);
#ifdef USE_WEIGHTED_QU
			m_oComponentSize.resize(nNoNodes);
#endif // USE_WEIGHTED_QU

			for (int nLoop = 0; nLoop < nNoNodes; nLoop++) {
				m_oFather[nLoop] = nLoop;
#ifdef USE_WEIGHTED_QU
				m_oComponentSize[nLoop] = 1;
#endif // USE_WEIGHTED_QU
			}
		}

		int FindRoot(int nNode) {
			while (nNode != m_oFather[nNode]) {
#ifndef USE_PATH_COMPRESSION
				nNode = m_arrnFather[nNode];
#else
				m_oFather[nNode] = m_oFather[m_oFather[nNode]];
				nNode = m_oFather[nNode];
#endif // USE_PATH_COMPRESSION
			}

			return nNode;
		}

		bool SameComponent(int nNode1, int nNode2)  {
			return FindRoot(nNode1) == FindRoot(nNode2);
		}

		int Connect(int nNode1, int nNode2) {
			nNode1 = FindRoot(nNode1);
			nNode2 = FindRoot(nNode2);

#ifndef USE_WEIGHTED_QU
			m_arrnFather[nNode1] = nNode2;
#else
			if (nNode1 == nNode2) {
				return m_oComponentSize[nNode1];
			} else if (m_oComponentSize[nNode1] < m_oComponentSize[nNode2]) {
				m_oFather[nNode1] = nNode2;
				return m_oComponentSize[nNode2] += m_oComponentSize[nNode1];
			} else {
				m_oFather[nNode2] = nNode1;
				return m_oComponentSize[nNode1] += m_oComponentSize[nNode2];
			}
#endif // USE_WEIGHTED_QU
		}

#ifdef USE_WEIGHTED_QU
		int GetComponentSize(int nNode) {
			nNode = FindRoot(nNode);
			return m_oComponentSize[nNode];
		}		
#endif // USE_WEIGHTED_QU

		void AppendNodes(int nNoNodesToAppend) {
			for (int nLoop = 0; nLoop < nNoNodesToAppend; nLoop++)
				AppendNode();
		}

		int GetSize() const {
			return m_oFather.size();
		}


	private:
		void AppendNode() {
			int nSize = m_oFather.size();
			m_oFather.push_back(nSize);
#ifdef USE_WEIGHTED_QU
			m_oComponentSize.push_back(1);
#endif // USE_WEIGHTED_QU
		}

		int m_nNumNodes;
		std::vector<int> m_oFather;
#ifdef USE_WEIGHTED_QU
		std::vector<int> m_oComponentSize;
#endif // USE_WEIGHTED_QU
};

/*************************************************************/

class PersonNameToPersonIdMap {
	public:
		int GetPersonId(const std::string &oName) {
			auto oIt = m_oNameToIdMap.find(oName);
			if (oIt == m_oNameToIdMap.end()) {
				int nSize = m_oNameToIdMap.size();
				return m_oNameToIdMap[oName] = nSize;
			} else {
				return oIt->second;
			}
		}

		int GetSize() const {
			return m_oNameToIdMap.size();
		}

	private:
		std::unordered_map<std::string, int> m_oNameToIdMap;
};

int main() {
	int nNoCases;

	UF oUF;

	for (std::cin >> nNoCases; nNoCases--; ) {
		PersonNameToPersonIdMap oPersonNamePersonIdMap;
		oUF.ReInit(0);

		int nNoFriendships;
		for (std::cin >> nNoFriendships; nNoFriendships--; ) {
			std::string oPerson1Name, oPerson2Name;
			std::cin >> oPerson1Name >> oPerson2Name;

			int nPerson1Id = oPersonNamePersonIdMap.GetPersonId(oPerson1Name);
			int nPerson2Id = oPersonNamePersonIdMap.GetPersonId(oPerson2Name);

			oUF.AppendNodes(oPersonNamePersonIdMap.GetSize() - oUF.GetSize());

			std::cout << oUF.Connect(nPerson1Id, nPerson2Id) << std::endl;
		}
	}

	return 0;
}