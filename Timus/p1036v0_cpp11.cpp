/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1036. Lucky Tickets                                              */
/*   http://acm.timus.ru/problem.aspx?num=1036                                */


#define USE_IOSTREAM

#ifndef USE_IOSTREAM
	#include <stdio.h>
#else
	#include <iostream>
#endif // USE_IOSTREAM
#ifndef ONLINE_JUDGE
	#define _CRT_SECURE_NO_WARNINGS 1
	#pragma warning(disable:4996)
#endif // ONLINE_JUDGE
#include <utility>
#include <algorithm>
#include <vector>
#include <iomanip>

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
	#include <chrono>
#endif // ONLINE_JUDGE


#define COMPILER_SUPPORTS_CONSTEXPR_
#define COMPILER_SUPPORTS__TEMPLATE_CLASS_PARTIAL_SPECIALIZATION_

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
//#define NO_DIGITS num_digits
//

		static_assert(IsPowerOf10(BASE) || IsPowerOf2(BASE), "TEST");

//		enum {
//			num_digits = Log10(BASE)
//		};

		static const int NO_DIGITS = IsPowerOf10(BASE) ? Log10(BASE) : Log2(BASE);

/*
		static
		typename std::enable_if<IsPowerOf10(BASE), const int>::type
		NO_DIGITS = Log10(BASE);

		static
		typename std::enable_if<!IsPowerOf10(BASE), const int>::type
		NO_DIGITS = Log10(BASE);
*/

		
		//typename std::enable_if<(!IsPowerOf10(BASE)), const int>::type
		//NO_DIGITS = Log10(BASE);

		// typedef typename std::enable_if<IsPowerOf10(BASE) && BASE <= 100, unsigned char>::type BASE_TYPE;
		// typedef class std::enable_if<false, unsigned char>::type BASE_TYPE;
		// typedef typename std::enable_if<(IsPowerOf10(BASE) && BASE > 100 && BASE < 10000), unsigned short>::type BASE_TYPE;

		// using BASE_TYPE1 = std::enable_if<IsPowerOf10(BASE) && BASE <= 100, unsigned char>::type;
		// typedef typename std::enable_if<false, unsigned char>::type BASE_TYPE;

		//template <class X>
		//using x = typename vector<X>;

//		typedef typename std::enable_if<(IsPowerOf10(BASE) & BASE > 0), unsigned char>::type DIGITS_TYPE;
//		typedef typename std::enable_if<(IsPowerOf10(BASE) && (BASE <= 100)), unsigned short>::type DIGITS_TYPE;

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

		#define POW_2_BASE_TYPE		typename std::conditional< \
										(IsPowerOf2(BASE) && NO_DIGITS <= 8), \
										unsigned char, \
										typename std::conditional< \
											(IsPowerOf2(BASE) && NO_DIGITS > 8 && NO_DIGITS <= 16), \
											unsigned short, \
											unsigned int \
										>::type \
									>::type

		typedef
		typename std::conditional<
			(IsPowerOf10(BASE)),
			POW_10_BASE_TYPE,
			POW_2_BASE_TYPE
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

		#define POW_2_MUL_TYPE					typename std::conditional< \
													(IsPowerOf2(BASE) && NO_DIGITS <= 4), \
														unsigned char, \
														typename std::conditional< \
															(IsPowerOf2(BASE) && NO_DIGITS > 4 && NO_DIGITS <= 8), \
															unsigned short, \
															typename std::conditional< \
																(IsPowerOf2(BASE) && NO_DIGITS > 8 && NO_DIGITS <= 16), \
																unsigned int, \
																unsigned long long \
															>::type \
														>::type \
												>::type

		typedef
		typename std::conditional<
			(IsPowerOf10(BASE)),
			POW_10_MUL_TYPE,
			POW_2_MUL_TYPE
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
	this->m_oVecDigits.resize(std::max(1, this->m_oVecDigits.crend() - oItRev));

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
		for (int nDigitIndex = this->m_oVecDigits.size() - 1; nDigitIndex >= 0; nDigitIndex--) {
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

		//printf("%s", "44444444444444444440000000000000000000000111111111111111111111112222222222222222222222233333333333333333333333");
		//return;
		//printf("%u", this->m_oVecDigits[this->m_oVecDigits.size() - 1]);
		//for (int nLoop = this->m_oVecDigits.size() - 2; nLoop >= 0; nLoop--)
		//	printf("%09d", this->m_oVecDigits[nLoop]);
		//return;

		//std::printf("%u", *this->m_oVecDigits.crbegin());
		//std::string oFormat("%00u");
		//oFormat[2] += BigInt<BASE>::NO_DIGITS;
		//std::for_each(
		//	this->m_oVecDigits.crbegin() + 1,
		//	this->m_oVecDigits.crend(),
		//	[&oFormat] (const typename BigInt<BASE>::BASE_TYPE nDigit) {
		//		std::printf(oFormat.c_str(), nDigit);
		//	}
		//);
	}
#endif // USE_IOSTREAM


#define USE_SIEVE_OF_ERATOSTHENES
#define USE_CLASSIC_METHOD__

void GenPrimes(std::vector<unsigned int> &roPrimes, const unsigned int nTo, const unsigned int nNoPrimes = 0) {
	roPrimes.reserve(nNoPrimes);

#ifdef USE_CLASSIC_METHOD
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (unsigned int nLoop = 13; nLoop <= nTo; nLoop += 2) {
		unsigned int nLim = (int)sqrt((double)nLoop);
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

	unsigned int nLim = (int)sqrt((double)nTo);
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
	int nN, nS;
#ifdef USE_IOSTREAM
	std::cin.tie(NULL);
	std::cin >> nN >> nS;
#else
	scanf("%u%u", &nN, &nS);
#endif // USE_IOSTREAM


#ifndef ONLINE_JUDGE
	auto oStart = std::chrono::high_resolution_clock::now();
#endif // ONLINE_JUDGE

	if (nS % 2 != 0) {
		std::printf("0");
	} else { 
		nS /= 2;
    
		//a = [1 if i < 1 else 0 for i in range(0, S + 1)]
		typedef BigInt<1000000000> BigInteger;
		// typedef BigInt<256> BigInteger;


#if 0
		std::vector<BigInteger> oVecPreviousStep(nS + 1);
		// oVecPreviousStep[0] = std::move(BigInteger(1));
		oVecPreviousStep[0] = BigInteger(1);
		int nLast = 0, nFirst = 0;

		std::vector<BigInteger> oVecCurrentStep(oVecPreviousStep);

		for (int i = 1; i <= nN; i++) {
			//std::vector<BigInteger> oVecCurrentStep(nS + 1);
			nLast = std::min(nS, nLast + 9);
			nFirst = std::max(nFirst, nS - 9 * (nN - i));
			for (int k = nFirst; k <= nLast; k++)
				for (int j = std::min(9, k); j; j--)
					oVecCurrentStep[k] += oVecPreviousStep[k - j];

			if (nFirst <= nLast)
				std::copy(oVecCurrentStep.cbegin() + nFirst, oVecCurrentStep.cbegin() + nLast + 1, oVecPreviousStep.begin() + nFirst);
			// oVecPreviousStep = oVecCurrentStep;
		}

		//print(a[S] ** 2)
		// std::cout << oVecPreviousStep[nS] << std::endl;
		BigInteger result = std::move(oVecPreviousStep[nS]);
		result *= result;
//		std::ios_base::sync_with_stdio(false);
//		std::cout << result << std::endl;
//		result.print();
		result.print();

#else
		// http://math.stackexchange.com/questions/1125070/counting-the-numbers-with-certain-sum-of-digits
		std::vector<unsigned int> oVecPrimes;
		GenPrimes(oVecPrimes, nN + nS, 110);

		typedef BigInt<1000000000> BigInteger;
		BigInteger oSolPlus(0), oSolMinus(0);

		for (int nI = 0; nI <= std::min(nN, nS / 10); nI++) {
			std::vector<unsigned int> oFactorization(oVecPrimes.size());

			FactorizeComb(oVecPrimes, oFactorization, nN, nI);
			FactorizeComb(oVecPrimes, oFactorization, nN + nS - 1 - nI * 10, nN - 1);

			typedef BigInt<1000000000> BigInteger;
			BigInteger oCurrent(1);
			auto oItPrime = oVecPrimes.cbegin();
			auto oItPower = oFactorization.cbegin();
			for ( ; oItPrime < oVecPrimes.cend(); oItPrime++, oItPower++) {
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
		oSolPlus *= oSolPlus;
		#ifdef USE_IOSTREAM
			std::cout << oSolPlus;
		#else
			oSolPlus.print();
		#endif // USE_IOSTREAM

#endif
            
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

	//BigInt<100> xx(123), yy(100);
	//std::cout << xx.NO_DIGITS << std::endl;

	//BigInt<1000> xxx(123), yyy(100);
	//xx += yyy;

	//xx += yy;

	//// xx.LOG10BASE = 11;

	//std::cout << sizeof(BigInt<10>::BASE_TYPE) << std::endl;
	//std::cout << sizeof(BigInt<100>::BASE_TYPE) << std::endl;
	//std::cout << sizeof(BigInt<1000>::BASE_TYPE) << std::endl;
 //   std::cout << sizeof(BigInt<10000>::BASE_TYPE) << std::endl;
 //   std::cout << sizeof(BigInt<100000>::BASE_TYPE) << std::endl;

	//std::cout << sizeof(BigInt<10>::MUL_TYPE) << std::endl;
	//std::cout << sizeof(BigInt<100>::MUL_TYPE) << std::endl;
	//std::cout << sizeof(BigInt<1000>::MUL_TYPE) << std::endl;
 //   std::cout << sizeof(BigInt<10000>::MUL_TYPE) << std::endl;
 //   std::cout << sizeof(BigInt<100000>::MUL_TYPE) << std::endl;

	return 0;
}