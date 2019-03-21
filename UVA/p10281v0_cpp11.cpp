/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10281 - Average Speed                                            */


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	int nLastTime = -1, nLastSpeed = 0;
	double lfTotalDistance = 0.0;

	cout << fixed << setprecision(2);
	for (string oLine; getline(cin, oLine); ) {
		stringstream oStream(oLine);

		string oTime;
		oStream >> oTime;

		int nTime = ((oTime[0] - '0') * 10 + (oTime[1] - '0')) * 60 * 60;
		nTime += ((oTime[3] - '0') * 10 + (oTime[4] - '0')) * 60;
		nTime += ((oTime[6] - '0') * 10 + (oTime[7] - '0'));

		int nSpeed;
		if (oStream >> nSpeed) {
			if (nLastTime > 0)
				lfTotalDistance += (nTime - nLastTime) / 3600.0 * nLastSpeed;
			nLastTime = nTime;
			nLastSpeed = nSpeed;
		} else {
			cout << oTime << " " << (lfTotalDistance + (nTime - nLastTime) / 3600.0 * nLastSpeed) << " km" << endl;
		}
	}

	return 0;
}