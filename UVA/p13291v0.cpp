/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13291 - Frosting on the Cake                                     */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roNumbersArray) {
	roNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}


int main() {
	for (int nN; cin >> nN; ) {
		vector<long long> oVecWidths;
		ReadArray(nN, oVecWidths);

		vector<vector<long long>> oVecPrecalculatedWidths(3, vector<long long>(3));
		const int nShift1 = nN % 3, nShift2 = ((nN % 3) + nN) % 3;
		for (int nLoop = 0; nLoop < nN; nLoop++) {
			oVecPrecalculatedWidths[0][nLoop % 3] += oVecWidths[nLoop];
			oVecPrecalculatedWidths[1][(nLoop + nShift1) % 3] += oVecWidths[nLoop];
			oVecPrecalculatedWidths[2][(nLoop + nShift2) % 3] += oVecWidths[nLoop];
		}

		vector<long long> oVecSol(3, 0);
		oVecWidths.clear();
		ReadArray(nN, oVecWidths);
		for (int nLoop = 0; nLoop < nN; nLoop++) {
			oVecSol[0] += oVecWidths[nLoop] * oVecPrecalculatedWidths[nLoop % 3][0];
			oVecSol[1] += oVecWidths[nLoop] * oVecPrecalculatedWidths[nLoop % 3][1];
			oVecSol[2] += oVecWidths[nLoop] * oVecPrecalculatedWidths[nLoop % 3][2];
		}


		cout << oVecSol[1] << " " << oVecSol[2] << " " << oVecSol[0] << endl;
	}
	
	return 0;
}