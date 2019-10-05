/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11835 - Formula 1                                                */


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// ===================================================================================
template<typename T>
std::istream& ReadArray(int nNoElements, std::vector<T> &roVecElementsArray, std::istream &roStream) {
	roVecElementsArray.reserve(nNoElements);
	while (nNoElements--) {
		T oElement;
		roStream >> oElement;
		roVecElementsArray.push_back(std::move(oElement));
	}

	return roStream;
}

template<typename T>
std::istream& ReadArray(std::vector<T> &roVectElementsArray, std::istream &roStream) {
	int nN;
	roStream >> nN;
	return ReadArray(nN, roVectElementsArray, roStream);
}

// ===================================================================================
template<typename T>
void WriteArray(const std::vector<T> &roVecNumbersArray) {
	if (!roVecNumbersArray.size())
		return;

	auto oIt = roVecNumbersArray.cbegin();
	std::cout << *oIt;

	while (++oIt != roVecNumbersArray.cend())
		std::cout << ' ' << *oIt;
}

// ===================================================================================
template <class ForwardIterator>
std::vector<ForwardIterator> all_max_elements(ForwardIterator first, ForwardIterator last)
{
	std::vector<ForwardIterator> oVectResult{ first };

	if (first != last) {
		while (++first != last) {
			if (*oVectResult[0] < *first) {
				oVectResult.resize(1);
				oVectResult[0] = first;
			} else if (*oVectResult[0] == *first) {
				oVectResult.push_back(first);
			}
		}
	}

	return oVectResult;
}

template <class ForwardIterator>
std::vector<size_t> all_max_elements_pos(ForwardIterator first, ForwardIterator last)
{
	std::vector<ForwardIterator> oVectMaxElements = all_max_elements(first, last);
	std::vector<size_t> oVecnResult;

	transform(
		begin(oVectMaxElements),
		end(oVectMaxElements),
		back_inserter(oVecnResult),
		std::bind(std::distance<ForwardIterator>, first, std::placeholders::_1)
	);

	return oVecnResult;
}

// ===================================================================================

using namespace std;

// ===================================================================================

class CScoringSystem : private vector<int> {
public:
	int GetPointsForPlace(int nPlace) const;
	friend std::istream& operator >> (std::istream &roStream, CScoringSystem &roScoringSystem);
};

int CScoringSystem::GetPointsForPlace(int nPlace) const {
	if (nPlace > size())
		return 0;
	return (*this)[nPlace - 1];
}

std::istream& operator >> (std::istream &roStream, CScoringSystem &roScoringSystem) {
	return ReadArray(roScoringSystem, roStream);
}

// ===================================================================================

class CRaceResult : private vector<int> {
	public:
		CRaceResult(int nNoPilots) : m_nNoPilots(nNoPilots) {};
		vector<int> GetPointsForEachPilot(const CScoringSystem &roScoringSystem) const;

	private:
		int m_nNoPilots;
		friend std::istream& operator >> (std::istream &roStream, CRaceResult &roRaceResult);
};

vector<int> CRaceResult::GetPointsForEachPilot(const CScoringSystem &roScoringSystem) const {
	using namespace std::placeholders;

	vector<int> oVecnPoints(m_nNoPilots);
	transform(
		this->cbegin(),
		this->cend(),
		oVecnPoints.begin(),
		std::bind(&CScoringSystem::GetPointsForPlace, roScoringSystem, _1)
	);

	return oVecnPoints;
}

std::istream& operator >> (std::istream &roStream, CRaceResult &roRaceResult) {
	return ReadArray(roRaceResult.m_nNoPilots, roRaceResult, roStream);
}

// ===================================================================================

class CRaceResults {
	public:
		bool IsEmpty() { return !m_nNoGrandPrix && !m_nNoPilots; }
		vector<size_t> GetChampions(const CScoringSystem &roScoringSystem) const;

	private:
		int m_nNoGrandPrix, m_nNoPilots;
		vector<CRaceResult> oVectRaceResult;
		friend std::istream& operator >> (std::istream &roStream, CRaceResults &roRaceResults);
};

vector<size_t> CRaceResults::GetChampions(const CScoringSystem &roScoringSystem) const {
	vector<int> oVecnPilotNoPoints(m_nNoPilots);
	for (const auto& oRaceResult : oVectRaceResult) {
		const auto oVecnoVecnPilotNoPointsForRace = oRaceResult.GetPointsForEachPilot(roScoringSystem);
		transform(
			oVecnoVecnPilotNoPointsForRace.cbegin(),
			oVecnoVecnPilotNoPointsForRace.cend(),
			oVecnPilotNoPoints.cbegin(),
			oVecnPilotNoPoints.begin(),
			std::plus<int>()
		);
	}

	auto oVecnChampions = all_max_elements_pos(begin(oVecnPilotNoPoints), end(oVecnPilotNoPoints));
	return oVecnChampions;
}

std::istream& operator >> (std::istream &roStream, CRaceResults &roRaceResults) {
	roStream >> roRaceResults.m_nNoGrandPrix >> roRaceResults.m_nNoPilots;
	for (int nRaceResultLoop = 0; nRaceResultLoop < roRaceResults.m_nNoGrandPrix; nRaceResultLoop++) {
		CRaceResult oRaceResult(roRaceResults.m_nNoPilots);
		roStream >> oRaceResult;
		roRaceResults.oVectRaceResult.push_back(move(oRaceResult));
	}

	return roStream;
}

// ===================================================================================


int main() {
	for (; ;) {
		CRaceResults oRaceResults;
		cin >> oRaceResults;
		if (oRaceResults.IsEmpty())
			break;

		int nNoScoringSystems;
		for (cin >> nNoScoringSystems; nNoScoringSystems--; ) {
			CScoringSystem oScoringSystem;
			cin >> oScoringSystem;

			auto oVecnChampions = oRaceResults.GetChampions(oScoringSystem);
			transform(oVecnChampions.cbegin(), oVecnChampions.cend(), oVecnChampions.begin(), bind(plus<size_t>(), 1, placeholders::_1));
			WriteArray(oVecnChampions);
			cout << endl;
		}

	}

	return 0;
}