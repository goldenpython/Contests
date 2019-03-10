/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11062 - Andy's Second Dictionary                                 */


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

template<typename T>
void PrintCollection(const T &roCollection, const std::string &roDelim, std::ostream &roStream) {
	if (!roCollection.size())
		return;

	auto oIt = prev(roCollection.cend());
	copy(roCollection.cbegin(), oIt, std::ostream_iterator<typename T::value_type>(roStream, roDelim.c_str()));
	std::cout << *oIt;
}

int main() {
	const auto oNewTable = ctype<char>::classic_table();
	vector<ctype<char>::mask> oNewMask(oNewTable, oNewTable + ctype<char>::table_size);
	for (int nChar = 1; nChar < 256; nChar++)
		if (!isalpha(nChar) && nChar != '-')
			oNewMask[nChar] |= ctype_base::space;
	cin.imbue(locale(cin.getloc(), new ctype<char>(oNewMask.data())));

	set<string> oSetStrings;
	for (string oWordFragment, oWord; cin >> oWordFragment; ) {
		auto oItFirstChar = oWordFragment.begin();
		auto oItLastChar = oWordFragment.end();

		transform(oItFirstChar, oItLastChar, oItFirstChar, [] (char cChar) { return tolower(cChar); });

		bool bIsFragment = (oWordFragment.back() == '-' && cin.peek() == '\n');
		if (bIsFragment)
			--oItLastChar;

		oWord.append(oItFirstChar, oItLastChar);
		
		if (!bIsFragment)
			oSetStrings.emplace(move(oWord));
	}

	PrintCollection(oSetStrings, "\n", cout);
	cout << endl;

	return 0;
}