/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1860. Fiborial                                                   */
/*   http://acm.timus.ru/problem.aspx?num=1860                                */


#include <iostream>
#include <vector>
#include <cmath>

#define USE_SIEVE_OF_ERATOSTHENES
#define USE_CLASSIC_METHOD__

template <typename TYPE_BITMAP>
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
	std::vector<TYPE_BITMAP> oPrimeMap(nTo + 1);
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


/*	ModAdd v1.1	*/
/*************************************************************/

template <typename T, typename U>
U Add(const T tA, const T tB) {
	U tResult = static_cast<U>(tA);
	tResult += static_cast<U>(tB);

	return tResult;
}

template <typename T, typename U, unsigned int R>
T ModAdd(const T tA, const T tB) {
	U tAdd = Add<T, U>(tA, tB);
	T tResult = static_cast<T>(tAdd % R);

	return tResult;
}

/*************************************************************/


/*	ModMult v1.1	*/
/*************************************************************/

template <typename T, typename U>
U Mult(const T tA, const T tB) {
	U tResult = static_cast<U>(tA);
	tResult *= static_cast<U>(tB);

	return tResult;
}

template <typename T, typename U, unsigned int R>
T ModMult(const T tA, const T tB) {
	U tMult = Mult<T, U>(tA, tB);
	T tResult = static_cast<T>(tMult % R);

	return tResult;
}

/*************************************************************/

/*	Mat2x2Mod v2.1	*/
/*************************************************************/

template <typename T, typename U, typename V, int R>
class Mat2x2Mod {
	public:
		Mat2x2Mod() {};
		Mat2x2Mod(const T &tA);
		Mat2x2Mod(const T &tA11, const T &tA12, const T &tA21, const T &tA22);
		Mat2x2Mod(const Mat2x2Mod& roRhs);

		Mat2x2Mod& operator = (const Mat2x2Mod &roRhs);

		Mat2x2Mod& operator *= (const Mat2x2Mod &roRhs);
		Mat2x2Mod& operator += (const Mat2x2Mod &roRhs);

	public:
		T GetAtPos11() const { return m_tM11; }
		T GetAtPos12() const { return m_tM12; }
		T GetAtPos21() const { return m_tM21; }
		T GetAtPos22() const { return m_tM22; }

		static Mat2x2Mod ZERO, ONE;
	private:
		T m_tM11, m_tM12, m_tM21, m_tM22;
};

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>::Mat2x2Mod(const T &tA) 
	: m_tM11(tA), m_tM12(0), m_tM21(0), m_tM22(tA)
{
}

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>::Mat2x2Mod(const T &tA11, const T &tA12, const T &tA21, const T &tA22) 
	: m_tM11(tA11), m_tM12(tA12), m_tM21(tA21), m_tM22(tA22)
{
}

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>::Mat2x2Mod(const Mat2x2Mod& roRhs) 
	: m_tM11(roRhs.m_tM11), m_tM12(roRhs.m_tM12), m_tM21(roRhs.m_tM21), m_tM22(roRhs.m_tM22)
{
}

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>& Mat2x2Mod<T, U, V, R>::operator =(const Mat2x2Mod& roRhs) 
{
	m_tM11 = roRhs.m_tM11;
	m_tM12 = roRhs.m_tM12;
	m_tM21 = roRhs.m_tM21;
	m_tM22 = roRhs.m_tM22;

	return *this;
}

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>& Mat2x2Mod<T, U, V, R>::operator *= (const Mat2x2Mod &roRhs) {
	Mat2x2Mod<T, U, V, R> tResult(*this);

	tResult.m_tM11 = ModAdd<T, U, R>(ModMult<T, V, R>(this->m_tM11, roRhs.m_tM11), ModMult<T, V, R>(this->m_tM12, roRhs.m_tM21));
	tResult.m_tM12 = ModAdd<T, U, R>(ModMult<T, V, R>(this->m_tM11, roRhs.m_tM12), ModMult<T, V, R>(this->m_tM12, roRhs.m_tM22));

	tResult.m_tM21 = ModAdd<T, U, R>(ModMult<T, V, R>(this->m_tM21, roRhs.m_tM11), ModMult<T, V, R>(this->m_tM22, roRhs.m_tM21));
	tResult.m_tM22 = ModAdd<T, U, R>(ModMult<T, V, R>(this->m_tM21, roRhs.m_tM12), ModMult<T, V, R>(this->m_tM22, roRhs.m_tM22));

	*this = tResult;

	return *this;
}

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R>& Mat2x2Mod<T, U, V, R>::operator += (const Mat2x2Mod &roRhs) {
	this->m_tM11 = ModAdd<T, U>(this->m_tM11, roRhs.m_tM11, R);
	this->m_tM12 = ModAdd<T, U>(this->m_tM12, roRhs.m_tM12, R);
	this->m_tM21 = ModAdd<T, U>(this->m_tM21, roRhs.m_tM21, R);
	this->m_tM22 = ModAdd<T, U>(this->m_tM22, roRhs.m_tM22, R);

	return *this;
}

/*************************************************************/

/*	Pow v1.1	*/
/*************************************************************/

template <typename T>
T Pow(const T tBase, unsigned int nExponent) {

	T tSum(1);
	T tExp(tBase);

	for (; nExponent; nExponent >>= 1) {
		if (nExponent & 0x1)
			tSum *= tExp;
		tExp *= tExp;
	}

	return tSum;
}

/*************************************************************/

template <typename T, typename U, typename V, int R>
Mat2x2Mod<T, U, V, R> MatFib(unsigned int nN) {

	Mat2x2Mod<T, U, V, R> oF(1, 1, 1, 0);
	oF = Pow(oF, nN);

	return oF;
}

template <typename T, typename U, typename V, int R>
void AdvanceFib(Mat2x2Mod<T, U, V, R> &roFibMat, T &roFirst, T &roSecond) {
//	if (nN <= 1)
//		return;

	T oFirst = ModAdd<T, U, R>(ModMult<T, V, R>(roFibMat.GetAtPos11() , roFirst), ModMult<T, V, R>(roFibMat.GetAtPos12(), roSecond));
	T oSecond = ModAdd<T, U, R>(ModMult<T, V, R>(roFibMat.GetAtPos21() , roFirst), ModMult<T, V, R>(roFibMat.GetAtPos22(), roSecond));

	roFirst = oFirst;
	roSecond = oSecond;
}

/*************************************************************/

int main() {
	unsigned int nN;
	const unsigned int MODULO = 1000000007;

	std::cin >> nN;

	if (nN <= 1) {
		std::cout << nN;
		return 0;
	}


	std::vector<unsigned int> oVecPrimes;
	GenPrimes<char>(oVecPrimes, nN);
	oVecPrimes.push_back(MODULO);

	unsigned int nResult = 1;

	for (auto oItPrime = oVecPrimes.cbegin(); *oItPrime <= nN; ++oItPrime) {
		const unsigned int nCurrentPrime = *oItPrime;
		const unsigned int nLim = nN/* - nCurrentPrime*/;

		bool bInitialized = false;
		Mat2x2Mod<unsigned int, unsigned int, unsigned long long, MODULO> oMat;
		if (nCurrentPrime * 2 <= nN)
			oMat = MatFib<unsigned int, unsigned int, unsigned long long, MODULO>(nCurrentPrime - 1);

		unsigned int nCurrentFib = 0, nPrevFib = 0;
		for (unsigned int nCurrentNumber = nCurrentPrime; nCurrentNumber <= nLim; ) {
			int nTempNumber = nCurrentNumber;
			int nPow = 0;
			while (!(nTempNumber % nCurrentPrime)) {
				nTempNumber /= nCurrentPrime;
				nPow++;
			}

			nPrevFib += nPow;
			nPow = nCurrentFib;
			nCurrentFib = ModAdd<unsigned int, unsigned int, MODULO>(nCurrentFib, nPrevFib);
			nPrevFib = nPow;

			if (nCurrentPrime + nCurrentNumber <= nN) {
				AdvanceFib<unsigned int, unsigned int, unsigned long long, MODULO>(oMat, nCurrentFib, nPrevFib);
			} else {
				oMat = MatFib<unsigned int, unsigned int, unsigned long long, MODULO>(nN - nCurrentNumber);
				AdvanceFib<unsigned int, unsigned int, unsigned long long, MODULO>(oMat, nCurrentFib, nPrevFib);
			}

			nCurrentNumber += nCurrentPrime;
		}

		
		nCurrentFib = ModAdd<unsigned int, unsigned int, MODULO>(nCurrentFib, 1);
		nResult = ModMult<unsigned int, unsigned long long, MODULO>(nCurrentFib, nResult);
	}

	std::cout << nResult;

	return 0;
}