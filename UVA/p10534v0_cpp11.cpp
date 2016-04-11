/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10534 - Wavio Sequence                                           */



#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

using namespace std;



/*  LIS v1.2    */
/*************************************************************/

template <typename IT, typename T, typename Comparator>
void LIS(const IT &roBegin, const IT &roEnd, vector<T> &roVecNumbersOut, const Comparator &roComp, const unique_ptr<vector<size_t>> &roVecLengths = nullptr) {
	const size_t MYINFINITY = static_cast<size_t>(~0);

	vector<size_t> oVecLISIndex;
	oVecLISIndex.push_back(MYINFINITY);
	oVecLISIndex.push_back(0);

	size_t nSize = roEnd - roBegin;

	if (roVecLengths != nullptr) {
		roVecLengths->reserve(nSize);
		roVecLengths->push_back(1);
	}

	vector<size_t> oVecILisPrevIndex;
	oVecILisPrevIndex.reserve(nSize);
	oVecILisPrevIndex.push_back(MYINFINITY);

	for (auto oIt = roBegin + 1; oIt != roEnd; oIt++) {
		auto oItPos = lower_bound(oVecLISIndex.begin() + 1, oVecLISIndex.end(), *oIt, [&roBegin, &roComp](const size_t nLHS, const T &roValue) { return roComp(*(roBegin + nLHS), roValue); });

		if (roVecLengths != nullptr)
			roVecLengths->push_back(oItPos - oVecLISIndex.begin());

		oVecILisPrevIndex.push_back(*(oItPos - 1));
		if (oItPos != oVecLISIndex.end())
			*oItPos = oIt - roBegin;
		else
			oVecLISIndex.push_back(oIt - roBegin);
	}

	vector<T> oVecResult;
	for (size_t nIndex = oVecLISIndex[oVecLISIndex.size() - 1]; nIndex != MYINFINITY; nIndex = oVecILisPrevIndex[nIndex])
		oVecResult.push_back(*(roBegin + nIndex));
	roVecNumbersOut = move(oVecResult);
	reverse(roVecNumbersOut.begin(), roVecNumbersOut.end());
}

template <typename IT, typename T>
void LIS(const IT &roBegin, const IT &roEnd, vector<T> &roVecNumbersOut) {
	LIS(roBegin, roEnd, roVecNumbersOut, std::less<T>());
}

/*************************************************************/


int main() {

	while (true) {
		int nNoInts;
		if (!(cin >> nNoInts))
			return 0;

		vector<int> oVecNumbers;
		while (nNoInts--) {
			int nN;
			cin >> nN;
			oVecNumbers.push_back(nN);
		}

		vector<int> oVecLIS;
//		unique_ptr<vector<size_t>> oVecLISSizeInc = make_unique<vector<size_t>>();
//		unique_ptr<vector<size_t>> oVecLISSizeDec = make_unique<vector<size_t>>();


		unique_ptr<vector<size_t>> oVecLISSizeInc(new vector<size_t>());
		unique_ptr<vector<size_t>> oVecLISSizeDec(new vector<size_t>());
		

		LIS(oVecNumbers.begin(), oVecNumbers.end(), oVecLIS, std::less<int>(), oVecLISSizeInc);
		LIS(oVecNumbers.rbegin(), oVecNumbers.rend(), oVecLIS, std::less<int>(), oVecLISSizeDec);

		size_t nMax = 0;
		transform(oVecLISSizeDec->rbegin(), oVecLISSizeDec->rend(), oVecLISSizeInc->begin(), oVecLISSizeInc->begin(), [](size_t nLHS, size_t nRHS) { return min(nLHS, nRHS) * 2 - 1; } );
		nMax = *(max_element(oVecLISSizeInc->cbegin(), oVecLISSizeInc->cend()));

		cout << nMax << endl;
	}

	return 0;
}