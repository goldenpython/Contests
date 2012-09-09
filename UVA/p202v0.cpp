/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 202 - Repeating Decimals                                         */


#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef struct REMAINDER_QUOTIENT_TAG {
	int m_iRemainder, m_iQuotient;
	int m_iIndex;

	bool operator == (const REMAINDER_QUOTIENT_TAG &oRHS) const { return m_iRemainder == oRHS.m_iRemainder && m_iQuotient == oRHS.m_iQuotient; };
} REMAINDER_QUOTIENT_STRUCT;

struct PREDICATE {
	bool operator()(const REMAINDER_QUOTIENT_TAG &lhs, const REMAINDER_QUOTIENT_TAG &rhs) const {
		return (lhs.m_iRemainder < rhs.m_iRemainder || lhs.m_iRemainder == rhs.m_iRemainder && lhs.m_iQuotient < rhs.m_iQuotient);
	}
};

typedef set<REMAINDER_QUOTIENT_STRUCT, PREDICATE> SET_TYPE;
typedef SET_TYPE::iterator SET_TYPE_ITERATOR;

typedef vector<int> DIGIT_LIST_TYPE;

#define MAX_DIGITS  50


int main() {
	int iA, iB;
	//MAP_TYPE oRemainderQuotient;
	SET_TYPE oRemainderQuotient;
	DIGIT_LIST_TYPE oDigits;

	while (cin >> iA >> iB) {
		oRemainderQuotient.clear();
		oDigits.clear();

		cout << iA << "/" << iB << " = ";

		int iC = iA / iB;
		iA %= iB;
		iA *= 10;

		cout << iC << ".";

		int iIndex = 0;

		while (1) {
			iC = iA / iB;
			int iR = iA % iB;
			if (!iR) {
				if (iC)
					oDigits.insert(oDigits.end(), iC);
				oDigits.insert(oDigits.end(), 0);
				iIndex = oDigits.size() - 1;
				break;
			}

			REMAINDER_QUOTIENT_STRUCT oP = {iR, iC, iIndex};
			//SET_TYPE_ITERATOR oIT = oRemainderQuotient.find(oP);
			SET_TYPE_ITERATOR oIT = oRemainderQuotient.find(oP);

			if (oIT == oRemainderQuotient.end()) {
				oRemainderQuotient.insert(oP);
				oDigits.insert(oDigits.end(), oP.m_iQuotient);
			} else {
				iIndex = oIT->m_iIndex;
				break;
			}

			iA = iR * 10;
			iIndex++;
		}

		int i;
		for (i = 0; i < iIndex; i++)
			cout << oDigits[i];
		cout << "(";

		int iSize = oDigits.size();
		for (i = iIndex; i < iSize && i < MAX_DIGITS + iIndex; i++)
			cout << oDigits[i];

		if (i == MAX_DIGITS + iIndex && i <= iSize)
			cout << "...";

		cout << ")";
		cout << "\n";
		cout << "   " << iSize - iIndex << " = number of digits in repeating cycle";
		cout << "\n\n";
	}

	return 0;
}
