/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13130 - Cacho                                                    */


#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))


#include <iostream>

class CDices {
	public:
		bool IsOk();

	private:
		int m_arrnDives[5];
		friend std::istream& operator >> (std::istream &roStream, CDices &roDices);
};

bool CDices::IsOk() {
	for (int nLoop = 1; nLoop < sizeof(m_arrnDives) / sizeof(m_arrnDives[0]); nLoop++)
		if (m_arrnDives[nLoop - 1] + 1 != m_arrnDives[nLoop])
			return false;

	return true;
}

std::istream& operator >> (std::istream &roStream, CDices &roDices) {
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
	for (auto &roElem : roDices.m_arrnDives) {
#else
	for (auto oItDives = std::begin(roDices.m_arrnDives); oItDives != std::end(roDices.m_arrnDives); ++oItDives) {
		auto &roElem = *oItDives;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		roStream >> roElem;
	}

	return roStream;
}

int main() {
	int nNoTestCases;

	for (std::cin >> nNoTestCases; nNoTestCases--; ) {
		CDices oDices;
		std::cin >> oDices;
		std::cout << (oDices.IsOk() ? 'Y' : 'N') << std::endl;
	}

	return 0;
}