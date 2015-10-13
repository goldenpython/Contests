/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12531 - Hours and Minutes                                        */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<bool> oVecAngles(360);

	for (int nH = 0; nH < 12; nH++) {
		for (int nM = 0; nM < 60; nM++) {
		int nAngH = nH * (360 / 12) + (nM / 12) * (360 / 60);
			int nAngM = nM * (360 / 60);
			nAngM -= nAngH;
			if (nAngM < 0)
				nAngM += 360;
			oVecAngles[nAngM] = true;
		}
	}

	int nAngle;
	while (cin >> nAngle)
		cout << (oVecAngles[nAngle % 180] ? "Y" : "N") << endl;

	return 0;
}