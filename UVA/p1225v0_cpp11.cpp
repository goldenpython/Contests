/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1225 - Digit Counting                                            */


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class NoDigits {
public:
	NoDigits();
	NoDigits(const NoDigits &roDigits);
	NoDigits(const NoDigits &&roDigits);

	NoDigits& operator = (const NoDigits &roDigits);
	NoDigits& operator = (const NoDigits &&roDigits);

	NoDigits operator + (const NoDigits &roDigits);
	NoDigits& operator += (const NoDigits &roDigits);

	unsigned int& operator [](std::size_t nIndex);
	const unsigned int& operator [](std::size_t nIndex) const;

private:
	vector<unsigned int> m_oVecDigits;
	static const unsigned int NODIGITS = 10;

	friend ostream& operator << (ostream &roStream, const NoDigits &roDigits);
};

NoDigits::NoDigits() : m_oVecDigits(NODIGITS) {
}

NoDigits::NoDigits(const NoDigits &roDigits) : m_oVecDigits(roDigits.m_oVecDigits) {
}

NoDigits::NoDigits(const NoDigits &&roDigits) : m_oVecDigits(move(roDigits.m_oVecDigits)) {
}

NoDigits& NoDigits::operator = (const NoDigits &roDigits) {
	m_oVecDigits = roDigits.m_oVecDigits;

	return *this;
}

NoDigits& NoDigits::operator = (const NoDigits &&roDigits) {
	m_oVecDigits = move(roDigits.m_oVecDigits);

	return *this;
}

NoDigits NoDigits::operator + (const NoDigits &roDigits) {
	NoDigits oTemp(*this);

	for (unsigned int nLoop = 0; nLoop < NODIGITS; nLoop++)
		oTemp[nLoop] += roDigits[nLoop];

	return oTemp;
}

NoDigits& NoDigits::operator += (const NoDigits &roDigits) {
	for (unsigned int nLoop = 0; nLoop < NODIGITS; nLoop++)
		m_oVecDigits[nLoop] += roDigits[nLoop];

	return *this;
}

unsigned int& NoDigits::operator [](std::size_t nIndex) {
	return m_oVecDigits[nIndex];
}

const unsigned int& NoDigits::operator [](std::size_t nIndex) const {
	return m_oVecDigits[nIndex];
}

ostream& operator << (ostream &roStream, const NoDigits &roDigits) {
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
	bool bPrintSpace = false;
	for (T &oElem : roDigits.m_oVecDigits) {
		if (bPrintSpace)
			roStream << " ";
		else
			bPrintSpace = true;
		roStream << oElem;
	}
#else
	const vector<unsigned int> roVector = roDigits.m_oVecDigits;
	roStream << *(roVector.begin());
	for_each(roVector.begin() + 1, roVector.end(), [&roStream](unsigned int nElem) { roStream << " " << nElem; });
#endif

	return roStream;
}

int main() {
	const int MAX = 10001;
	vector<NoDigits> oVecSol(1);
	oVecSol.reserve(MAX);
	for (unsigned int nLoop = 1; nLoop < 10; nLoop++) {
		NoDigits oTemp;
		oTemp[nLoop] = 1;
		oVecSol.push_back(move(oTemp));
	}

	for (unsigned int nLoop = 10; nLoop < MAX; nLoop++) {
		NoDigits oTemp(oVecSol[nLoop / 10]);
		oTemp[nLoop % 10]++;
		oVecSol.push_back(move(oTemp));
	}

	partial_sum(oVecSol.begin(), oVecSol.end(), oVecSol.begin());

	unsigned int nNoCases;
	for (cin >> nNoCases; nNoCases--; ) {
		unsigned int nN;
		cin >> nN;
		cout << oVecSol[nN] << endl;
	}

	return 0;
}