/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 231 - Testing the CATCHER                                        */



#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

using namespace std;



/*  LIS v1.1    */
/*************************************************************/

template <typename T, typename Comparator>
void LIS(const vector<T> &roVecNumbersIn, vector<T> &roVecNumbersOut, const Comparator &roComp, const unique_ptr<vector<size_t>> &roVecLengths = nullptr) {
	const size_t MYINFINITY = static_cast<size_t>(~0);

	vector<size_t> oVecLISIndex;
	oVecLISIndex.push_back(MYINFINITY);
	oVecLISIndex.push_back(0);

	if (roVecLengths != nullptr) {
		roVecLengths->reserve(roVecNumbersIn.size());
		roVecLengths->push_back(1);
	}

	vector<size_t> oVecILisPrevIndex;
	oVecILisPrevIndex.reserve(roVecNumbersIn.size());
	oVecILisPrevIndex.push_back(MYINFINITY);

	for (auto oIt = roVecNumbersIn.cbegin() + 1; oIt != roVecNumbersIn.cend(); oIt++) {
		auto oItPos = lower_bound(oVecLISIndex.begin() + 1, oVecLISIndex.end(), *oIt, [&roVecNumbersIn, &roComp](const size_t nLHS, const T &roValue) { return roComp(roVecNumbersIn[nLHS], roValue); });

		if (roVecLengths != nullptr)
			roVecLengths->push_back(oItPos - oVecLISIndex.begin());

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
	int nCaseLoop = 1;
	while (true) {
		vector<int> oVecNumbers;
		while (true) {
			int nN;
			cin >> nN;
			if (nN == -1)
				break;
			oVecNumbers.push_back(nN);
		}

		if (!oVecNumbers.size())
			return 0;

		vector<int> oVecLIS;
		LIS(oVecNumbers, oVecLIS, std::greater<int>());

		if (nCaseLoop > 1)
			cout << endl;
		cout << "Test #" << nCaseLoop++ << ":" << endl << "  maximum possible interceptions: " << oVecLIS.size() << endl;
	}

	return 0;
}