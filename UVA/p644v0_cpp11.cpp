/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 644 - Immediate Decodability                                     */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string oLine;
	vector<string> oVecEncodings;
	int nNoSet = 1;

	while (true) {
		if (!getline(cin, oLine))
			break;

		oVecEncodings.push_back(oLine);

		if (oLine == "9") {
			bool bHasSol = true;
			for (auto oIt1 = oVecEncodings.begin(); oIt1 != oVecEncodings.end(); oIt1++) {
				for (auto oIt2 = oIt1 + 1; oIt2 != oVecEncodings.end(); oIt2++) {
					const string &roPrefix = oIt1->size() > oIt2->size() ? *oIt2 : *oIt1;
					const string &roString = oIt1->size() <= oIt2->size() ? *oIt2 : *oIt1;
					if (!roString.compare(0, roPrefix.size(), roPrefix)) {
						bHasSol = false;
						oIt1 = oVecEncodings.end() - 1;
						break;
					}
				}
			}

			cout << "Set " << nNoSet <<  (bHasSol ? " is immediately decodable" : " is not immediately decodable") << endl;

			nNoSet++;
			oVecEncodings.clear();
		}
	}

	return 0;
}