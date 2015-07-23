/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10229 - Modular Fibonacci                                        */


#include <iostream>


/*	ModAdd v1.0	*/
/*************************************************************/

template <typename T, typename U>
U Add(const T tA, const T tB) {
	U tResult = static_cast<U>(tA);
	tResult += static_cast<U>(tB);

	return tResult;
}

template <typename T, typename U>
T ModAdd(const T tA, const T tB, const T tR) {
	U tAdd = Add<T, U>(tA, tB);
	T tResult = static_cast<T>(tAdd % tR);

	return tResult;
}

/*************************************************************/




/*	ModMult v1.0	*/
/*************************************************************/

template <typename T, typename U>
U Mult(const T tA, const T tB) {
	U tResult = static_cast<U>(tA);
	tResult *= static_cast<U>(tB);

	return tResult;
}

template <typename T, typename U>
T ModMult(const T tA, const T tB, const T tR) {
	U tMult = Mult<T, U>(tA, tB);
	T tResult = static_cast<T>(tMult % tR);

	return tResult;
}

/*************************************************************/





/*	Mat2x2Mod v1.0	*/
/*************************************************************/

template <typename T, typename U, typename V>
class Mat2x2Mod {
	protected:
		Mat2x2Mod(const T &tA, const T &tR);
		Mat2x2Mod(const T &tA11, const T &tA12, const T &tA21, const T &tA22, const T &tR);
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
		const T m_tR;
};

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>::Mat2x2Mod(const T &tA, const T &tR) 
	: m_tM11(tA), m_tM12(0), m_tM21(0), m_tM22(tA), m_tR(tR)
{
}

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>::Mat2x2Mod(const T &tA11, const T &tA12, const T &tA21, const T &tA22, const T &tR) 
	: m_tM11(tA11), m_tM12(tA12), m_tM21(tA21), m_tM22(tA22), m_tR(tR)
{
}

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>::Mat2x2Mod(const Mat2x2Mod& roRhs) 
	: m_tM11(roRhs.m_tM11), m_tM12(roRhs.m_tM12), m_tM21(roRhs.m_tM21), m_tM22(roRhs.m_tM22), m_tR(roRhs.m_tR)
{
}

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>& Mat2x2Mod<T, U, V>::operator =(const Mat2x2Mod& roRhs) 
{
	m_tM11 = roRhs.m_tM11;
	m_tM12 = roRhs.m_tM12;
	m_tM21 = roRhs.m_tM21;
	m_tM22 = roRhs.m_tM22;

	return *this;
}

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>& Mat2x2Mod<T, U, V>::operator *= (const Mat2x2Mod &roRhs) {
	Mat2x2Mod<T, U, V> tResult(*this);

	tResult.m_tM11 = ModAdd<T, U>(ModMult<T, V>(this->m_tM11, roRhs.m_tM11, this->m_tR), ModMult<T, V>(this->m_tM12, roRhs.m_tM21, this->m_tR), this->m_tR);
	tResult.m_tM12 = ModAdd<T, U>(ModMult<T, V>(this->m_tM11, roRhs.m_tM12, this->m_tR), ModMult<T, V>(this->m_tM12, roRhs.m_tM22, this->m_tR), this->m_tR);

	tResult.m_tM21 = ModAdd<T, U>(ModMult<T, V>(this->m_tM21, roRhs.m_tM11, this->m_tR), ModMult<T, V>(this->m_tM22, roRhs.m_tM21, this->m_tR), this->m_tR);
	tResult.m_tM22 = ModAdd<T, U>(ModMult<T, V>(this->m_tM21, roRhs.m_tM12, this->m_tR), ModMult<T, V>(this->m_tM22, roRhs.m_tM22, this->m_tR), this->m_tR);

	*this = tResult;

	return *this;
}

template <typename T, typename U, typename V>
Mat2x2Mod<T, U, V>& Mat2x2Mod<T, U, V>::operator += (const Mat2x2Mod &roRhs) {
	this->m_tM11 = ModAdd<T, U>(this->m_tM11, roRhs.m_tM11, this->m_tR);
	this->m_tM12 = ModAdd<T, U>(this->m_tM12, roRhs.m_tM12, this->m_tR);
	this->m_tM21 = ModAdd<T, U>(this->m_tM21, roRhs.m_tM21, this->m_tR);
	this->m_tM22 = ModAdd<T, U>(this->m_tM22, roRhs.m_tM22, this->m_tR);

	return *this;
}

/*************************************************************/



/*	Mat2x2ModR v1.0	*/
/*************************************************************/

template <typename T, typename U, typename V, int R>
class Mat2x2ModR : public Mat2x2Mod<T, U, V> {
	public:
		Mat2x2ModR(const T &tA);
		Mat2x2ModR(const T &tA11, const T &tA12, const T &tA21, const T &tA22);


		Mat2x2ModR& operator = (const Mat2x2ModR &roRhs);

		Mat2x2ModR& operator += (const Mat2x2ModR &roRhs);
		Mat2x2ModR& operator *= (const Mat2x2ModR &roRhs);

		static Mat2x2ModR ZERO, ONE;
};

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R>::Mat2x2ModR(const T &tA) 
	: Mat2x2Mod<T, U, V>(tA, R) {
}

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R>::Mat2x2ModR(const T &tA11, const T &tA12, const T &tA21, const T &tA22)
	: Mat2x2Mod<T, U, V>(tA11, tA12, tA21, tA22, R) {
}

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R>& Mat2x2ModR<T, U, V, R>::operator =(const Mat2x2ModR<T, U, V, R> &roRhs) {
	Mat2x2Mod<T, U, V>::operator =(roRhs);
	return *this;
}

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R>& Mat2x2ModR<T, U, V, R>::operator +=(const Mat2x2ModR<T, U, V, R> &roRhs) {
	Mat2x2Mod<T, U, V>::operator +=(roRhs);
	return *this;
}

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R>& Mat2x2ModR<T, U, V, R>::operator *=(const Mat2x2ModR<T, U, V, R> &roRhs) {
	Mat2x2Mod<T, U, V>::operator *=(roRhs);
	return *this;
}

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R> Mat2x2ModR<T, U, V, R>::ZERO(T(0), T(0), T(0), T(0));

template <typename T, typename U, typename V, int R>
Mat2x2ModR<T, U, V, R> Mat2x2ModR<T, U, V, R>::ONE(T(1), T(0), T(0), T(1));

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
int Solve1(unsigned int nN) {
	typedef Mat2x2ModR<T, U, V, R> Mat;

	Mat oF(1, 1, 1, 0);
	oF = Pow<Mat>(oF, nN);

	return oF.GetAtPos12();;
}

int Solve(unsigned int nN, unsigned int nM) {
	switch (nM) {
		case 0:
			return Solve1<int, int, int, 1 << 0>(nN);
		case 1:
			return Solve1<int, int, int, 1 << 1>(nN);
		case 2:
			return Solve1<int, int, int, 1 << 2>(nN);
		case 3:
			return Solve1<int, int, int, 1 << 3>(nN);
		case 4:
			return Solve1<int, int, int, 1 << 4>(nN);
		case 5:
			return Solve1<int, int, int, 1 << 5>(nN);
		case 6:
			return Solve1<int, int, int, 1 << 6>(nN);
		case 7:
			return Solve1<int, int, int, 1 << 7>(nN);
		case 8:
			return Solve1<int, int, int, 1 << 8>(nN);
		case 9:
			return Solve1<int, int, int, 1 << 9>(nN);
		case 10:
			return Solve1<int, int, int, 1 << 10>(nN);
		case 11:
			return Solve1<int, int, int, 1 << 11>(nN);
		case 12:
			return Solve1<int, int, int, 1 << 12>(nN);
		case 13:
			return Solve1<int, int, int, 1 << 13>(nN);
		case 14:
			return Solve1<int, int, int, 1 << 14>(nN);
		case 15:
			return Solve1<int, int, int, 1 << 15>(nN);
		case 16:
			return Solve1<int, int, long long, 1 << 16>(nN);
		case 17:
			return Solve1<int, int, long long, 1 << 17>(nN);
		case 18:
			return Solve1<int, int, long long, 1 << 18>(nN);
		case 19:
			return Solve1<int, int, long long, 1 << 19>(nN);
		case 20:
			return Solve1<int, int, long long, 1 << 20>(nN);
		default:
			return -1;
	}
}

int main() {
	unsigned int nN, nM;
	while (std::cin >> nN >> nM) {
		std::cout << Solve(nN, nM) << std::endl;
	}

	return 0;
}