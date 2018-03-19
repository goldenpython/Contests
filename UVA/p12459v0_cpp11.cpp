/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12459 - Bees' ancestors                                          */


#define USE_IOSTREAM

#ifndef USE_IOSTREAM
	#include <stdio.h>
#else
	#include <iostream>
	#include <iomanip>
#endif // USE_IOSTREAM

#ifndef ONLINE_JUDGE
	#define _CRT_SECURE_NO_WARNINGS 1
	#pragma warning(disable:4996)
#endif // ONLINE_JUDGE

#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
	#include <chrono>
#endif // ONLINE_JUDGE


#define COMPILER_SUPPORTS_CONSTEXPR_
#define COMPILER_SUPPORTS__TEMPLATE_CLASS_PARTIAL_SPECIALIZATION

#ifdef COMPILER_SUPPORTS_CONSTEXPR
constexpr bool IsPowerOf(int nNumber, int nPower) {
	return nNumber == 1 || (nNumber % nPower == 0 && IsPowerOf(nNumber / nPower, nPower));
}

constexpr int Log(int nNumber, int nBase) {
	return nNumber == 1 ? 0 : (Log(nNumber / nBase, nBase) + 1);
}
#else
template<int N, int BASE>
struct IS_POWER_OF {
	enum {
		value = (N % BASE == 0) && IS_POWER_OF<N / BASE, BASE>::value,
		log = 1 + IS_POWER_OF<N / BASE, BASE>::log
	};
};

#ifdef COMPILER_SUPPORTS__TEMPLATE_CLASS_PARTIAL_SPECIALIZATION
template<int BASE>
struct IS_POWER_OF<1, BASE> {
	enum {
		value = 1,
		log = 0
	};
};
#else
template<>
struct IS_POWER_OF<1, 10> {
	enum {
		value = 1,
		log = 0
	};
};

template<>
struct IS_POWER_OF<1, 2> {
	enum {
		value = 1,
		log = 0
	};
};

template<>
struct IS_POWER_OF<0, 10> {
	enum {
		value = 1,
		log = 0
	};
};
#endif // COMPILER_SUPPORTS__TEMPLATE_CLASS_PARTIAL_SPECIALIZATION
#endif // COMPILER_SUPPORTS_CONSTEXPR

#ifdef COMPILER_SUPPORTS_CONSTEXPR
#else
#define IsPowerOf(N, BASE)	(IS_POWER_OF<N, BASE>::value)
#define Log(N, BASE)		(IS_POWER_OF<N, BASE>::log)
#endif //

#define IsPowerOf10(N)	(IsPowerOf(N, 10))
#define Log10(N)		(Log(N, 10))

#define IsPowerOf2(N)	(IsPowerOf(N, 2))
#define Log2(N)			(Log(N, 2))

template <int BASE = 10>
class BigInt {
public:

	static_assert(IsPowerOf10(BASE), "TEST");

	static const int NO_DIGITS = Log10(BASE);

public:
	BigInt() : m_oVecDigits(1) {}

	BigInt(int nNumber) {
		do {
			m_oVecDigits.push_back(nNumber % BASE);
			nNumber /= BASE;
		} while (nNumber);
	}

	BigInt(const BigInt &roRHS) : m_oVecDigits(roRHS.m_oVecDigits) {}
	BigInt(const BigInt &&roRHS) : m_oVecDigits(std::move(roRHS.m_oVecDigits)) {}
	BigInt& operator =(const BigInt &roRHS) { m_oVecDigits = roRHS.m_oVecDigits; return *this; }
	BigInt& operator =(const BigInt &&roRHS) { m_oVecDigits = std::move(roRHS.m_oVecDigits); return *this; }

	BigInt& operator += (const BigInt& roRHS);
	BigInt& operator -= (const BigInt& roRHS);
	BigInt& operator *= (const BigInt& roRHS);

#ifdef USE_IOSTREAM
	template <int BASE1>
	friend std::ostream& operator << (std::ostream &roStream, const BigInt<BASE1> &roNumber);
#else
	void print();
#endif // USE_IOSTREAM

public:
#define POW_10_BASE_TYPE	typename std::conditional< \
										(IsPowerOf10(BASE) && NO_DIGITS <= 2), \
										unsigned char, \
										typename std::conditional< \
											(IsPowerOf10(BASE) && BASE > 100 && BASE < 100000), \
											unsigned short, \
											unsigned int \
										>::type \
									>::type


	typedef
		typename std::conditional<
		(IsPowerOf10(BASE)),
		POW_10_BASE_TYPE,
		unsigned int
		>::type BASE_TYPE;



#define POW_10_MUL_TYPE					typename std::conditional< \
													(IsPowerOf10(BASE) && NO_DIGITS <= 1), \
													unsigned char, \
													typename std::conditional< \
														(IsPowerOf10(BASE) && NO_DIGITS >= 2 && NO_DIGITS < 3), \
														unsigned short, \
														typename std::conditional< \
															(IsPowerOf10(BASE) && NO_DIGITS >= 3 && NO_DIGITS <= 4), \
															unsigned int, \
															unsigned long long \
														>::type \
													>::type \
												>::type

	typedef
		typename std::conditional<
		(IsPowerOf10(BASE)),
		POW_10_MUL_TYPE,
		unsigned int
		>::type MUL_TYPE;

private:
	std::vector<BASE_TYPE> m_oVecDigits;
};

template <int BASE>
BigInt<BASE>& BigInt<BASE>::operator += (const BigInt<BASE>& roRHS) {
	if (roRHS.m_oVecDigits.size() > this->m_oVecDigits.size())
		this->m_oVecDigits.resize(roRHS.m_oVecDigits.size());

	auto oItLHS = this->m_oVecDigits.begin();
	auto oItRHS = roRHS.m_oVecDigits.cbegin();
	BASE_TYPE nTransport = 0;
	for (
		;
		oItRHS != roRHS.m_oVecDigits.cend();
		++oItLHS, ++oItRHS
		) {
		nTransport += (*oItRHS + *oItLHS);
		if (nTransport >= BASE) {
			*oItLHS = nTransport - BASE;
			nTransport = 1;
		}
		else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
	}

	while (nTransport && oItLHS != this->m_oVecDigits.end()) {
		nTransport += *oItLHS;
		if (nTransport >= BASE) {
			*oItLHS = nTransport - BASE;
			nTransport = 1;
		}
		else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
		oItLHS++;
	}

	if (nTransport)
		this->m_oVecDigits.push_back(nTransport);

	return *this;
}

template <int BASE>
BigInt<BASE>& BigInt<BASE>::operator -= (const BigInt<BASE>& roRHS) {
	if (roRHS.m_oVecDigits.size() > this->m_oVecDigits.size())
		this->m_oVecDigits.resize(roRHS.m_oVecDigits.size());

	auto oItLHS = this->m_oVecDigits.begin();
	auto oItRHS = roRHS.m_oVecDigits.cbegin();
	BASE_TYPE nTransport = 0;
	for (
		;
		oItRHS != roRHS.m_oVecDigits.cend();
		++oItLHS, ++oItRHS
		) {
		nTransport = (*oItLHS - *oItRHS - nTransport);
		if (nTransport >= BASE) {
			*oItLHS = nTransport + BASE;
			nTransport = 1;
		}
		else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
	}

	while (nTransport && oItLHS != this->m_oVecDigits.end()) {
		nTransport = *oItLHS - nTransport;
		if (nTransport >= BASE) {
			*oItLHS = nTransport + BASE;
			nTransport = 1;
		}
		else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
		oItLHS++;
	}

	if (nTransport) {
		// assert(nTransport == 0, "");
	}

	auto oItRev = this->m_oVecDigits.crbegin();
	for (; oItRev != this->m_oVecDigits.crend() && !*oItRev; oItRev++)
		;
	this->m_oVecDigits.resize(std::max<size_t>(1, this->m_oVecDigits.crend() - oItRev));

	return *this;
}

template <int BASE>
BigInt<BASE>& BigInt<BASE>::operator *= (const BigInt<BASE>& roRHS) {
	std::vector<BASE_TYPE> oVecResult;
	// oVecResult.reserve(this->m_oVecDigits.size() + roRHS.m_oVecDigits.size() - 1);
	oVecResult.resize(this->m_oVecDigits.size() + roRHS.m_oVecDigits.size() - 1);

	// oVecResult.resize(this->m_oVecDigits.size() * roRHS.m_oVecDigits.size() - 1);

	for (auto oItLHSDigit = this->m_oVecDigits.cbegin(); oItLHSDigit != this->m_oVecDigits.cend(); oItLHSDigit++) {
		MUL_TYPE nTransportMul = 0, nCurrentMulDigit = static_cast<MUL_TYPE>(*oItLHSDigit);
		BASE_TYPE nTrasportAdd = 0;
		auto oItResultAddPointer = oVecResult.begin() + (oItLHSDigit - this->m_oVecDigits.cbegin());
		for (auto oItRHSDigit = roRHS.m_oVecDigits.cbegin(); oItRHSDigit != roRHS.m_oVecDigits.cend(); oItRHSDigit++, oItResultAddPointer++) {
			nTransportMul += nCurrentMulDigit * *oItRHSDigit;
			nTrasportAdd += static_cast<BASE_TYPE>(nTransportMul % BASE);
			nTransportMul /= BASE;

			nTrasportAdd += *oItResultAddPointer;
			*oItResultAddPointer = nTrasportAdd % BASE;
			nTrasportAdd /= BASE;
		}

		nTrasportAdd += static_cast<BASE_TYPE>(nTransportMul);

		while (nTrasportAdd) {
			if (oItResultAddPointer == oVecResult.end())
				oItResultAddPointer = oVecResult.insert(oVecResult.end(), 0);
			nTrasportAdd += *oItResultAddPointer;
			*oItResultAddPointer = nTrasportAdd % BASE;
			nTrasportAdd /= BASE;
		}
	}

	this->m_oVecDigits = std::move(oVecResult);

	return *this;
}

#ifdef USE_IOSTREAM
template <int BASE>
std::ostream& operator << (std::ostream &roStream, const BigInt<BASE> &roNumber) {
	roStream << static_cast<unsigned int>(*roNumber.m_oVecDigits.crbegin());
	// std::cout << std::setfill('0') << std::setw(BigInt<BASE>::NO_DIGITS);
	std::for_each(
		roNumber.m_oVecDigits.crbegin() + 1,
		roNumber.m_oVecDigits.crend(),
		[](const typename BigInt<BASE>::BASE_TYPE nDigit) {
		std::cout << std::setfill('0') << std::setw(BigInt<BASE>::NO_DIGITS) << static_cast<unsigned int>(nDigit);
	}
	);
	return roStream;
}
#else
template <int BASE>
void BigInt<BASE>::print() {
	if (this->m_oVecDigits.size() == 1 && !this->m_oVecDigits[0]) {
		printf("0");
		return;
	}

	std::vector<char> szLine(this->m_oVecDigits.size() * NO_DIGITS + 1, '0');
	szLine[szLine.size() - 1] = '\0';
	for (int nDigitIndex = static_cast<int>(this->m_oVecDigits.size()) - 1; nDigitIndex >= 0; nDigitIndex--) {
		char *psz = &szLine[(this->m_oVecDigits.size() - 1 - nDigitIndex) * NO_DIGITS + NO_DIGITS - 1];
		BASE_TYPE nDigit = this->m_oVecDigits[nDigitIndex];
		while (nDigit) {
			*psz = '0' + (nDigit % 10);
			nDigit /= 10;
			psz--;
		}
	}

	char *psz = &szLine[0];
	while (*psz == '0')
		psz++;
	printf("%s", psz);
	return;
}
#endif // USE_IOSTREAM

int main() {
	const int MAX_GENERATIONS = 81;
	typedef BigInt<10000> BIGINT_TYPE;
	std::vector<BIGINT_TYPE> oVecFibs = {1, 1};
	for (int nLoop = 2; nLoop < MAX_GENERATIONS; nLoop++) {
		BIGINT_TYPE oCurrentFib(oVecFibs[nLoop - 1]);
		oCurrentFib += oVecFibs[nLoop - 2];
		oVecFibs.emplace_back(oCurrentFib);
	}

	for (int nN; (std::cin >> nN), nN; )
		std::cout << oVecFibs[nN] << std::endl;

	return 0;
}