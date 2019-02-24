/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 626 - Ecosystem                                                  */



#include <iostream>
#include <vector>

using namespace std;

int main() {
	for (int nNoSpecies; cin >> nNoSpecies; ) {
		vector<vector<int>> oVec2nMatrix(nNoSpecies, vector<int>(nNoSpecies));
		for (int nRowLoop = 0; nRowLoop < nNoSpecies; nRowLoop++)
			for (int nColumnLoop = 0; nColumnLoop < nNoSpecies; nColumnLoop++)
				cin >> oVec2nMatrix[nRowLoop][nColumnLoop];

		int nTotal = 0;
		for (int nLoop1 = 0; nLoop1 < nNoSpecies; nLoop1++) {
			for (auto nLoop2 = 1; nLoop2 < nLoop1; nLoop2++)
				if (oVec2nMatrix[nLoop1][nLoop2])
					for (auto nLoop3 = 0; nLoop3 < nLoop2; nLoop3++)
						if (oVec2nMatrix[nLoop2][nLoop3] && oVec2nMatrix[nLoop3][nLoop1]) {
							cout << nLoop1 + 1 << ' ' << nLoop2 + 1 << ' ' << nLoop3 + 1 << endl;
							nTotal++;
						}

			for (auto nLoop2 = nLoop1 + 1; nLoop2 < nNoSpecies; nLoop2++)
				if (oVec2nMatrix[nLoop1][nLoop2])
					for (auto nLoop3 = nLoop2 + 1; nLoop3 < nNoSpecies; nLoop3++)
						if (oVec2nMatrix[nLoop2][nLoop3] && oVec2nMatrix[nLoop3][nLoop1]) {
							cout << nLoop1 + 1 << ' ' << nLoop2 + 1 << ' ' << nLoop3 + 1 << endl;
							nTotal++;
						}
		}

		cout << "total:" << nTotal << endl << endl;
	}

	return 0;
}