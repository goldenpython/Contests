/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 516 - Prime Land                                                 */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

void GenPrimes(vector<int> &roPrimes, int nTo, int nNoPrimes) {
	roPrimes.reserve(nNoPrimes);
	roPrimes.push_back(2);roPrimes.push_back(3);roPrimes.push_back(5);roPrimes.push_back(7);roPrimes.push_back(11);
	
	for (int i = 13; i <= nTo; i += 2) {
		int lim = (int) sqrt((double)i);
		int j;
		for (j = 1; roPrimes[j] <= lim; j++)
			if (!(i % roPrimes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			roPrimes.push_back(i);
	}
}

int main() {

	vector<int> oPrimes;
	GenPrimes(oPrimes, 181, 181);

	while (true) {
		string oLine;
		getline(cin, oLine);
		if (oLine[0] == '0')
			break;

		stringstream oStream(oLine);

		int nN = 1;
		while (oStream.good()) {
			int nBase, nPower;
			oStream >> nBase >> nPower;
			while (nPower--)
				nN *= nBase;
		}

		nN--;
		vector<pair<int, int> > oSol;
		for (vector<int>::iterator oIt = oPrimes.begin(); oIt != oPrimes.end() && *oIt <= nN; oIt++) {
			if (!(nN % *oIt)) {
				int nCount = 0;
				while (!(nN % *oIt)) {
					nN /= *oIt;
					nCount++;
				}
				oSol.push_back(make_pair(*oIt, nCount));
			}
		}
		if (nN > 1)
			oSol.push_back(make_pair(nN, 1)); 

		vector<pair<int, int> >::reverse_iterator oIt = oSol.rbegin();
		cout << oIt->first << " " << oIt->second;
		for (++oIt; oIt != oSol.rend(); ++oIt) {
			cout << " " << oIt->first << " " << oIt->second;
		}
		cout << endl;
	}

	return 0;
}