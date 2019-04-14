/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10541 - Stripe                                                   */


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
			do  {
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
		} else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
	}

	while (nTransport && oItLHS != this->m_oVecDigits.end()) {
		nTransport += *oItLHS;
		if (nTransport >= BASE) {
			*oItLHS = nTransport - BASE;
			nTransport = 1;
		} else {
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
		} else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
	}

	while (nTransport && oItLHS != this->m_oVecDigits.end()) {
		nTransport = *oItLHS - nTransport;
		if (nTransport >= BASE) {
			*oItLHS = nTransport + BASE;
			nTransport = 1;
		} else {
			*oItLHS = nTransport;
			nTransport = 0;
		}
		oItLHS++;
	}

	if (nTransport) {
		// assert(nTransport == 0, "");
	}

	auto oItRev = this->m_oVecDigits.crbegin();
	for ( ; oItRev != this->m_oVecDigits.crend() && !*oItRev; oItRev++)
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
			[] (const typename BigInt<BASE>::BASE_TYPE nDigit) { 
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


#define USE_SIEVE_OF_ERATOSTHENES
#define USE_CLASSIC_METHOD__

void GenPrimes(std::vector<unsigned int> &roPrimes, const unsigned int nTo, const unsigned int nNoPrimes = 0) {
	roPrimes.reserve(nNoPrimes);

#ifdef USE_CLASSIC_METHOD
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (unsigned int nLoop = 13; nLoop <= nTo; nLoop += 2) {
		unsigned int nLim = (int)std::sqrt(static_cast<double>(nLoop));
		unsigned int nLoopPrimes;
		for (nLoopPrimes = 1; roPrimes[nLoopPrimes] <= nLim; nLoopPrimes++)
			if (!(nLoop % roPrimes[nLoopPrimes])) {
			nLoopPrimes = -1;
				break;
			}

		if (nLoopPrimes != -1)
			roPrimes.push_back(nLoop);
	}
#endif // USE_CLASSIC_METHOD

#ifdef USE_SIEVE_OF_ERATOSTHENES
	std::vector<char> oPrimeMap(nTo + 1);
	roPrimes.push_back(2);

	unsigned int nLim = (int)sqrt(static_cast<double>(nTo));
	unsigned int nLoop;

	for (nLoop = 3; nLoop <= nLim; nLoop += 2) {
		if (!oPrimeMap[nLoop]) {
			roPrimes.push_back(nLoop);
			for (unsigned int nCurrentPrime = nLoop * nLoop; nCurrentPrime <= nTo; nCurrentPrime += nLoop * 2)
				oPrimeMap[nCurrentPrime] = 1;
		}
	}

	for ( ; nLoop <= nTo; nLoop += 2)
		if (!oPrimeMap[nLoop])
			roPrimes.push_back(nLoop);
#endif // USE_SIEVE_OF_ERATOSTHENES
}

void Factorize(const std::vector<unsigned int> &roPrimes, std::vector<unsigned int> &roPowers, int nN, const int nSign) {
	auto oItPrime = roPrimes.cbegin();
	auto oItPower = roPowers.begin();
	for (; nN > 1 && oItPrime < roPrimes.cend(); oItPrime++, oItPower++) {
		while (nN % *oItPrime == 0) {
			*oItPower += nSign;
			nN /= *oItPrime;
		}
	}
}

void FactorizeComb(const std::vector<unsigned int> &roPrimes, std::vector<unsigned int> &roPowers, int nN, int nK) {
	int nK2 = nK > nN / 2 ? nK : nN - nK;

	for (int nLoop = nK2 + 1; nLoop <= nN; nLoop++)
		Factorize(roPrimes, roPowers, nLoop, 1);
	for (int nLoop = nN - nK2; nLoop >= 2; nLoop--)
		Factorize(roPrimes, roPowers, nLoop, -1);
}

int main() {
	int nNoTestCases;

	std::vector<unsigned int> oVecPrimes;
	GenPrimes(oVecPrimes, 250, 60);

#ifdef USE_IOSTREAM
	std::cin.tie(NULL);
	std::cin >> nNoTestCases;
#else
	scanf("%d", &nNoTestCases);
#endif // USE_IOSTREAM

	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nLength, nNoNumbers;

#ifdef USE_IOSTREAM
		std::cin >> nLength >> nNoNumbers;
#else
		scanf("%d %d", &nLength, &nNoNumbers);
#endif // USE_IOSTREAM

		int nTotalBlackSize = 0;
		for (int nNumbersLoop = 0; nNumbersLoop < nNoNumbers; nNumbersLoop++) {
			int nCurrentSize;
#ifdef USE_IOSTREAM
			std::cin >> nCurrentSize;
#else
			scanf("%d", &nCurrentSize);
#endif // USE_IOSTREAM

			nTotalBlackSize += nCurrentSize;
		}

#ifndef ONLINE_JUDGE
		auto oStart = std::chrono::high_resolution_clock::now();
#endif // ONLINE_JUDGE

		{
			typedef BigInt<1000000000> BigInteger;

			BigInteger oSolPlus(0), oSolMinus(0);

			http://math.stackexchange.com/questions/1125070/counting-the-numbers-with-certain-sum-of-digits
			int nS = nLength - nTotalBlackSize + 2 - (nNoNumbers + 1), nN = nNoNumbers + 1, nMax = nS + 1;

			if (nMax > 0) {
				for (int nI = 0; nI <= std::min(nN, nS / nMax); nI++) {
					std::vector<unsigned int> oFactorization(oVecPrimes.size());

					FactorizeComb(oVecPrimes, oFactorization, nN, nI);
					FactorizeComb(oVecPrimes, oFactorization, nN + nS - 1 - nI * nMax, nN - 1);

					BigInteger oCurrent(1);
					auto oItPrime = oVecPrimes.cbegin();
					auto oItPower = oFactorization.cbegin();
					for (; oItPrime < oVecPrimes.cend(); oItPrime++, oItPower++) {
						for (unsigned int nPowerLoop = 0; nPowerLoop < *oItPower; nPowerLoop++) {
							BigInteger oCurrentPrime(*oItPrime);
							oCurrent *= oCurrentPrime;
						}
					}

					if (nI % 2 == 0)
						oSolPlus += oCurrent;
					else
						oSolMinus += oCurrent;
				}

				oSolPlus -= oSolMinus;
			}


#ifdef USE_IOSTREAM
			std::cout << oSolPlus << std::endl;
#else
			oSolPlus.print();
			printf("\n");
#endif // USE_IOSTREAM

		}
	}

#ifndef ONLINE_JUDGE
	auto oFinish = std::chrono::high_resolution_clock::now();
	auto oMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(oFinish - oStart);
	#ifdef USE_IOSTREAM
		std::cout << std::endl << (oMicroseconds.count() / 1000000.0) << "seconds\n";
	#else
		printf("\n%lf seconds\n", (oMicroseconds.count() / 1000000.0));
	#endif // USE_IOSTREAM
#endif // ONLINE_JUDGE

	return 0;
} 