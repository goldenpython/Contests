/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11057 - Exact Sum                                                */



#include <stdio.h>
#include <map>

using namespace std;

int main() {
	int nNoNumbers;
	map<int, int> oMap;
	
	while (scanf("%d", &nNoNumbers) == 1) {
		oMap.clear();

		for (int nLoop = 0; nLoop < nNoNumbers; nLoop++) {
			int nNumber;
			scanf("%d", &nNumber);
			oMap[nNumber]++;
		}

		int nTargetSum;
		scanf("%d", &nTargetSum);
		if (!(nTargetSum & 0x1) && oMap[nTargetSum >> 1] >= 2) {
			printf("Peter should buy books whose prices are %d and %d.\n\n", nTargetSum >> 1, nTargetSum >> 1);
			continue;
		}

		
		for (map<int, int>::iterator oIt = oMap.upper_bound(nTargetSum >> 1); oIt != oMap.end(); oIt++) {
			if (oMap.find(nTargetSum - oIt->first) != oMap.end()) {
				printf("Peter should buy books whose prices are %d and %d.\n\n", nTargetSum - oIt->first, oIt->first);
				break;
			}
		}
	}

	return 0;
}