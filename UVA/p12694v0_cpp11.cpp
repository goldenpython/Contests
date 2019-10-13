/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12694 - Meeting Room Arrangement                                 */


// from https://en.wikipedia.org/wiki/Interval_scheduling

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
std::istream& ReadArray(std::vector<T> &roVectElementsArray, std::istream &roStream) {

	while (true) {
		T oElement;
		if (!(roStream >> oElement) || !oElement)
			break;
		roVectElementsArray.push_back(std::move(oElement));
	}

	return roStream;
}

class CInterval : private pair<int, int> {
	public:
		int GetStartTime() const			{	return first;		}
		int GetEndTime() const				{	return second;		}
		bool operator !() const				{	return !first && !second;	} 
		int operator < (const CInterval &roIntervalRHS) const {	return GetEndTime() < roIntervalRHS.GetEndTime(); }

	private:

		friend std::istream& operator >> (std::istream &roStream, CInterval &roInterval);
};

std::istream& operator >> (std::istream &roStream, CInterval &roInterval) {
	return (roStream >> roInterval.first >> roInterval.second);
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		vector<CInterval> oVecoIntervals;
		ReadArray(oVecoIntervals, cin);
		sort(oVecoIntervals.begin(), oVecoIntervals.end());

		int nSolution = 0, nReferenceEndTime = -1;
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		for (const auto &roInterval : oVecoIntervals) {
#else
		for (auto roItInterval = oVecoIntervals.cbegin(); roItInterval != oVecoIntervals.cend(); ++roItInterval) {
			const auto &roInterval = *roItInterval;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP

			if (nReferenceEndTime <= roInterval.GetStartTime()) {
				nReferenceEndTime = roInterval.GetEndTime();
				nSolution++;
			}
		}

		cout << nSolution << endl;
	}

	return 0;
}