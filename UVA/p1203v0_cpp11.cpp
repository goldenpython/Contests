/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1203 - Argus                                                     */


#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	typedef struct IdPeriodCurrent {
		int m_nId, m_nPeriod, m_nCurrent;
		bool operator < (const IdPeriodCurrent &roRHS) const { return !(this->m_nCurrent < roRHS.m_nCurrent || (this->m_nCurrent == roRHS.m_nCurrent && this->m_nId < roRHS.m_nId)); }
	} IDPERIODCURRENT;
	priority_queue<IDPERIODCURRENT> oQueue;

	string oLine;
	while ((cin >> oLine) && oLine != "#") {
		int nId, nPeriod;
		cin >> nId >> nPeriod;

		IDPERIODCURRENT oObj = {nId, nPeriod, nPeriod};
		oQueue.push(oObj);
	}

	int nQueries;
	cin >> nQueries; 
	while (nQueries--) {
		auto oCurrent = oQueue.top();
		oQueue.pop();
		cout << oCurrent.m_nId << endl;
		oCurrent.m_nCurrent += oCurrent.m_nPeriod;
		oQueue.push(oCurrent);
	}

	return 0;
}