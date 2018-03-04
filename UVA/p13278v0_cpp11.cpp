/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13278 - Angry Birds Transformers                                 */


#include <iostream>
#include <map>

using namespace std;

void UpdatePositionAction(map<int, int> &roMapPositionAction, int nPosition, int nAction) {
	auto oIt = roMapPositionAction.find(nPosition);

	if (oIt == roMapPositionAction.end())
		roMapPositionAction.insert(make_pair(nPosition, nAction));
	else
		oIt->second += nAction;
}

int main() {
	for (int nN; (cin >> nN), nN; ) {
		map<int, int> oMapPositionAction;
		while (nN--) {
			int nX, nY;
			cin >> nX >> nY;

			UpdatePositionAction(oMapPositionAction, nX + nY + 1, -1);
			UpdatePositionAction(oMapPositionAction, nX - nY, +1);
		}

		int nMaxVisibleObjects = 0, nCurrentVisibleObjects = 0;
		for (auto oIt = oMapPositionAction.cbegin(); oIt != oMapPositionAction.cend(); ++oIt)
			if ((nCurrentVisibleObjects += oIt->second) > nMaxVisibleObjects)
				nMaxVisibleObjects = nCurrentVisibleObjects;

		cout << nMaxVisibleObjects << endl;
	}
	return 0;
}