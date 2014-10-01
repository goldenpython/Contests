/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 612 - DNA Sorting                                                */

/*   http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=553 */



#include <stdio.h>
#include <string.h>

#include <vector>
#include <algorithm>

using namespace std;


#define MAX_LINE_LEN	55
#define MAX_STRINGS		110

#define USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION

#ifndef USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION

class DNA_SEQUENCE_HELPER {
	friend class DNA_SEQUENCE;

	private:
		DNA_SEQUENCE_HELPER();

		int m_arrnCharMap[256];
};

DNA_SEQUENCE_HELPER::DNA_SEQUENCE_HELPER() {
	memset(m_arrnCharMap, 0, sizeof(m_arrnCharMap));
	m_arrnCharMap['A'] = 0;
	m_arrnCharMap['C'] = 1;
	m_arrnCharMap['G'] = 2;
	m_arrnCharMap['T'] = 3;
}

#endif // USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION

class DNA_SEQUENCE {
	public:
		DNA_SEQUENCE() {};
		void Load();
		char * GetString();

		static void SetSequencesLength(int nLength);

		static bool Comparator(DNA_SEQUENCE *lhs, DNA_SEQUENCE *rhs);

	private:
		char m_szSequence[MAX_LINE_LEN];

		static int s_nSequencesLength;
		int nNumInversions;

#ifndef USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION
		static DNA_SEQUENCE_HELPER s_oHelperComputeObject;
#endif // USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION
};

int DNA_SEQUENCE::s_nSequencesLength = 0;

#ifndef USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION
DNA_SEQUENCE_HELPER DNA_SEQUENCE::s_oHelperComputeObject;
#endif // USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION

void DNA_SEQUENCE::Load() {
	gets(m_szSequence);

	nNumInversions = 0;
#ifdef USE_BRUTE_FORCE_FOR_NO_INVERSIONS_CALCULATION
	for (int nLoop1 = 0; nLoop1 < s_nSequencesLength; nLoop1++)
		for (int nLoop2 = nLoop1 + 1; nLoop2 < s_nSequencesLength; nLoop2++)
			if (m_szSequence[nLoop1] > m_szSequence[nLoop2])
	nNumInversions++;
#else 
	int nCurrentIndex;
	int arrnCharCount[4];

	nCurrentIndex = s_oHelperComputeObject.m_arrnCharMap[m_szSequence[0]];
	arrnCharCount[0] = arrnCharCount[1] = arrnCharCount[2] = arrnCharCount[3] = 0;
	arrnCharCount[nCurrentIndex] = 1;

	for (int nLoopString = 1; m_szSequence[nLoopString]; nLoopString++) {
		nCurrentIndex = s_oHelperComputeObject.m_arrnCharMap[m_szSequence[nLoopString]];

		switch (nCurrentIndex) {
			case 0:
				nNumInversions += arrnCharCount[1];
			case 1:
				nNumInversions += arrnCharCount[2];
			case 2:
				nNumInversions += arrnCharCount[3];
		}

		arrnCharCount[nCurrentIndex]++;
	}
#endif
}

void DNA_SEQUENCE::SetSequencesLength(int nLength) {
	s_nSequencesLength = nLength;
}

bool DNA_SEQUENCE::Comparator(DNA_SEQUENCE *lhs, DNA_SEQUENCE *rhs) {
	return lhs->nNumInversions < rhs->nNumInversions;
}

char * DNA_SEQUENCE::GetString() {
	return m_szSequence; 
}

int main() {
	int nNoTestCases, nN, nM;
	char szLine[MAX_LINE_LEN];

	vector<DNA_SEQUENCE *> arroSequences;
	arroSequences.reserve(MAX_STRINGS);
	for (int nLoop = 0; nLoop < MAX_STRINGS; nLoop++)
		arroSequences.insert(arroSequences.end(), new DNA_SEQUENCE());

	for (sscanf(gets(szLine), "%d", &nNoTestCases); nNoTestCases; nNoTestCases--) {
		gets(szLine);
		sscanf(gets(szLine), "%d %d", &nN, &nM);

		DNA_SEQUENCE::SetSequencesLength(nN);
		for (int nLoopString = 0; nLoopString < nM; nLoopString++)
			arroSequences[nLoopString]->Load();

		stable_sort(arroSequences.begin(), arroSequences.begin() + nM, DNA_SEQUENCE::Comparator);

		for (int nLoopString = 0; nLoopString < nM; nLoopString++)
			//puts(arroSequences[nLoopString]->GetString());
			printf("%s\n", arroSequences[nLoopString]->GetString());

		if (nNoTestCases > 1)
			//puts("");
			printf("\n");
	}

	return 0;
}