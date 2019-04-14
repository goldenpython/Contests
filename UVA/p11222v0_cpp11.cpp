/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11222 - Only I did it!                                           */


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void ReadArray(std::vector<T> &roVectElementsArray) {
	int nN;
	std::cin >> nN;
	roVectElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVectElementsArray.push_back(std::move(oElement));
	}
}

template<typename T>
void PrintCollection(const T &roCollection, const std::string &roDelim) {
	copy(roCollection.cbegin(), prev(roCollection.cend()), std::ostream_iterator<typename T::value_type>(std::cout, roDelim.c_str()));
	if (roCollection.size())
		std::cout << *(prev(roCollection.cend()));
}

using namespace std;

void SetDifference(vector<int> &roSetLHS, const vector<int> &roSetRHS) {
	auto oIt = set_difference(roSetLHS.cbegin(), roSetLHS.cend(), roSetRHS.cbegin(), roSetRHS.cend(), roSetLHS.begin());
	roSetLHS.resize(oIt - roSetLHS.begin());
}

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		vector<vector<int>> oVec2nProblems(3);
		for_each(
			oVec2nProblems.begin(),
			oVec2nProblems.end(), 
			[](vector<int> &roVecnProblems) {
				ReadArray(roVecnProblems); 
				sort(roVecnProblems.begin(), roVecnProblems.end()); 
			}
		);


		auto oVec2nUniqueProblems = oVec2nProblems;
		for (int nLoopFriend = 0; nLoopFriend < 3; nLoopFriend++) {
			SetDifference(oVec2nUniqueProblems[nLoopFriend], oVec2nProblems[(nLoopFriend + 1) % 3]);
			SetDifference(oVec2nUniqueProblems[nLoopFriend], oVec2nProblems[(nLoopFriend + 2) % 3]);
		}
		
		auto oItMaxElement = max_element(
			oVec2nUniqueProblems.cbegin(), 
			oVec2nUniqueProblems.cend(), 
			[] (const vector<int> &roVecnProblemsLHS, const vector<int> &roVecnProblemsRHS) {
				return roVecnProblemsLHS.size() < roVecnProblemsRHS.size(); 
			}
		);
		auto nMaxSize = oItMaxElement->size();

		cout << "Case #" << nCaseLoop << ':' << endl;
		for (int nLoopFriend = 0; nLoopFriend < 3; nLoopFriend++)
			if (oVec2nUniqueProblems[nLoopFriend].size() == nMaxSize) {
				cout << (nLoopFriend + 1) << ' ' << nMaxSize;
				if (nMaxSize) {
					cout << ' ';
					PrintCollection(oVec2nUniqueProblems[nLoopFriend], " ");
				}
				cout << endl;
			}
	}

	return 0;
}