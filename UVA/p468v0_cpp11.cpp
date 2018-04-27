/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 468 - Key to Success                                             */


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class CCharStats {
	public:
		CCharStats(const string &roString);
		int GetChar2FreqIndex(char cChar);
		char GetFreqIndex2Char(int nIndex);
	private:
		vector<int> m_oVecnChar2FreqIndex;
		vector<int> m_oVecnFreqIndex2Char;
};

CCharStats::CCharStats(const string &roString)
	: m_oVecnChar2FreqIndex(256) 
{
	struct CHARFREQ {
		char cChar;
		int nFreq;
	};

	vector<CHARFREQ> oVecCharFreq(256);

	for (auto cChar : roString) {
		oVecCharFreq[cChar].cChar = cChar;
		oVecCharFreq[cChar].nFreq++;
	}

	sort(
		oVecCharFreq.begin(),
		oVecCharFreq.end(),
		[](const CHARFREQ &roLHS, const CHARFREQ &roRHS) { return roLHS.nFreq > roRHS.nFreq; }
	);

	for (int nLoop = 0; oVecCharFreq[nLoop].nFreq; nLoop++) {
		m_oVecnChar2FreqIndex[oVecCharFreq[nLoop].cChar] = nLoop;
		m_oVecnFreqIndex2Char.push_back(oVecCharFreq[nLoop].cChar);
	}
}

int CCharStats::GetChar2FreqIndex(char cChar) {
	return m_oVecnChar2FreqIndex[cChar];
}

char CCharStats::GetFreqIndex2Char(int nIndex) {
	return m_oVecnFreqIndex2Char[nIndex];
}

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		string oLine1, oLine2;
		cin >> oLine1 >> oLine2;
		CCharStats oCharFreq1(oLine1);
		CCharStats oCharFreq2(oLine2);

		transform(
			oLine2.begin(), 
			oLine2.end(),
			oLine2.begin(),
			[&roCharFreq2 = oCharFreq2, &roCharFreq1 = oCharFreq1](char cChar) { 
				return roCharFreq1.GetFreqIndex2Char(roCharFreq2.GetChar2FreqIndex(cChar)); 
			}
		);

		cout << oLine2 << endl;
		if (nNoTestCases)
			cout << endl;
	}

	return 0;
}