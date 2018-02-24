/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1481 - Genome Evolution                                          */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int MAX_GENES = 3000 + 1;
	vector<int> oVecnChromosome1, oVecnGenePosInChromosome2;
	oVecnChromosome1.reserve(MAX_GENES); oVecnGenePosInChromosome2.reserve(MAX_GENES);

	for (int nSize; (cin >> nSize), nSize; ) {
		oVecnChromosome1.clear(); oVecnGenePosInChromosome2.resize(nSize + 1);

		int nGene;
		for (int nLoop = 0; nLoop < nSize; nLoop++) {
			cin >> nGene;
			oVecnChromosome1.push_back(nGene);
		}
		for (int nLoop = 0; nLoop < nSize; nLoop++) {
			cin >> nGene;
			oVecnGenePosInChromosome2[nGene] = nLoop;
		}

		int nTotalMatches = 0;
		for (auto oItBegin = oVecnChromosome1.cbegin(); oItBegin != oVecnChromosome1.cend(); ++oItBegin) {
			int nPotentialMatchBeginPos = oVecnGenePosInChromosome2[*oItBegin];
			int nPotentialMatchEndPos = nPotentialMatchBeginPos;
			for (auto oItEnd = next(oItBegin); oItEnd != oVecnChromosome1.cend(); ++oItEnd) {
				auto nCurrentGenePosInChromosome2 = oVecnGenePosInChromosome2[*oItEnd];
				if (nCurrentGenePosInChromosome2 < nPotentialMatchBeginPos)
					nPotentialMatchBeginPos = nCurrentGenePosInChromosome2;
				else if (nCurrentGenePosInChromosome2 > nPotentialMatchEndPos)
					nPotentialMatchEndPos = nCurrentGenePosInChromosome2;

				if (oItEnd - oItBegin == nPotentialMatchEndPos - nPotentialMatchBeginPos)
					nTotalMatches++;
			}
		}

		cout << nTotalMatches << endl;
	}

	return 0;
}