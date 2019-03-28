/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 855 - Lunch in Grid City                                         */


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename TypeIt>
typename TypeIt::value_type GetMedian(TypeIt oItFirst, TypeIt oItLast) {
	auto oItMiddle = next(oItFirst, (distance(oItFirst, oItLast) - 1) / 2);
	nth_element(oItFirst, oItMiddle, oItLast);
	return *oItMiddle;
}

template <typename TypeContainer>
typename TypeContainer::value_type GetMedian(TypeContainer &roContainer) {
	return GetMedian(roContainer.begin(), roContainer.end());
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nS, nA;
		cin >> nS >> nA;

		int nNoFriends;
		cin >> nNoFriends;

		vector<int> oVecnRows, oVecnColumns;
		for (oVecnRows.reserve(nNoFriends), oVecnColumns.reserve(nNoFriends); nNoFriends--; ) {
			int nRow, nColumn;
			cin >> nRow >> nColumn;
			oVecnRows.push_back(nRow);
			oVecnColumns.push_back(nColumn);
		}

		cout << "(Street: " << GetMedian(oVecnRows) << ", Avenue: " << GetMedian(oVecnColumns) << ")" << endl;
	}

	return 0;
}