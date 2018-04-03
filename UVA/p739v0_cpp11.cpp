/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 739 - Soundex Indexing                                           */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> GetCharEncodingVector() {
	vector<char> oVecCharMapping(256);

	oVecCharMapping['B'] = oVecCharMapping['P'] = oVecCharMapping['F'] = oVecCharMapping['V'] = '1';
	oVecCharMapping['C'] = oVecCharMapping['S'] = oVecCharMapping['K'] = oVecCharMapping['G']
		= oVecCharMapping['J'] = oVecCharMapping['Q'] = oVecCharMapping['X']
		= oVecCharMapping['Z'] = '2';
	oVecCharMapping['D'] = oVecCharMapping['T'] = '3';
	oVecCharMapping['L'] = '4';
	oVecCharMapping['M'] = oVecCharMapping['N'] = '5';
	oVecCharMapping['R'] = '6';

	return oVecCharMapping;
}

template<int N>
class WhitespacePrinter {
	public:
		friend ostream& operator << (ostream &oStream, const WhitespacePrinter &oW) {
			for (int nN = N; nN--; oStream << " ")
				;
			return oStream;
		}
};

int main() {
	string oLine;
	const vector<char> oVecCharMapping = GetCharEncodingVector();

	cout << WhitespacePrinter<9>() << "NAME                     SOUNDEX CODE" << endl;

	while (getline(cin, oLine)) {
		string oEncoding("0000");
		oEncoding[0] = oLine[0];
		int nEncodingIndex = 1;
		char nPrevCharEncoding = oVecCharMapping[oLine[0]];
		for (auto oIt = oLine.cbegin() + 1; oIt != oLine.cend(); ++oIt) {
			char nCurrentCharEncoding = oVecCharMapping[*oIt];
			if (nCurrentCharEncoding && nCurrentCharEncoding != nPrevCharEncoding) {
				oEncoding[nEncodingIndex++] = nCurrentCharEncoding;
				if (nEncodingIndex == oEncoding.size())
					break;
			}

			nPrevCharEncoding = nCurrentCharEncoding;
		}

		cout << WhitespacePrinter<9>() << oLine;
		for (int nLoop = 35 - 10 - static_cast<int>(oLine.size()); nLoop--; )
			cout << " ";
		cout << oEncoding << endl;
	}

	cout << WhitespacePrinter<19>() << "END OF OUTPUT" << endl;

	return 0;
}