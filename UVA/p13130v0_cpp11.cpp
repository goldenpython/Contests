/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13130 - Cacho                                                    */



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
	for (auto &roElem : roDices.m_arrnDives)
		roStream >> roElem;

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