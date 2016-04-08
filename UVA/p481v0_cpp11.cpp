/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 481 - What Goes Up                                               */


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;



/*  LIS v1.0    */
/*************************************************************/

template <typename T, typename Comparator>
void LIS(const vector<T> &roVecNumbersIn, vector<T> &roVecNumbersOut, const Comparator &roComp) {
	const size_t MYINFINITY = static_cast<size_t>(~0);

	vector<size_t> oVecLISIndex;
	oVecLISIndex.push_back(MYINFINITY);
	oVecLISIndex.push_back(0);

	vector<size_t> oVecILisPrevIndex;
	oVecILisPrevIndex.reserve(roVecNumbersIn.size());
	oVecILisPrevIndex.push_back(MYINFINITY);

	for (auto oIt = roVecNumbersIn.cbegin() + 1; oIt != roVecNumbersIn.cend(); oIt++) {
		auto oItPos = lower_bound(oVecLISIndex.begin() + 1, oVecLISIndex.end(), *oIt, [&roVecNumbersIn, &roComp](const size_t nLHS, const T &roValue) { return roComp(roVecNumbersIn[nLHS], roValue); });

		oVecILisPrevIndex.push_back(*(oItPos - 1));
		if (oItPos != oVecLISIndex.end())
			*oItPos = oIt - roVecNumbersIn.cbegin();
		else
			oVecLISIndex.push_back(oIt - roVecNumbersIn.cbegin());
	}

	vector<T> oVecResult;
	for (size_t nIndex = oVecLISIndex[oVecLISIndex.size() - 1]; nIndex != MYINFINITY; nIndex = oVecILisPrevIndex[nIndex])
		oVecResult.push_back(roVecNumbersIn[nIndex]);
	roVecNumbersOut = move(oVecResult);
	reverse(roVecNumbersOut.begin(), roVecNumbersOut.end());
}

template <typename T>
void LIS(const vector<T> &roVecNumbersIn, vector<T> &roVecNumbersOut) {
	LIS(roVecNumbersIn, roVecNumbersOut, std::less<T>());
}

/*************************************************************/


int main() {
	vector<int> oVecNumbers;
	int nN;
	while (cin >> nN)
		oVecNumbers.push_back(nN);

	vector<int> oVecLIS;
	LIS(oVecNumbers, oVecLIS /*, std::greater<int>()*/);

	cout << oVecLIS.size() << endl << '-' << endl;
	for (auto oIt = oVecLIS.cbegin(); oIt < oVecLIS.cend(); oIt++)
		cout << *oIt << endl;

	return 0;
}