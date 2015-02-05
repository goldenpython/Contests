/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12820 - Cool Word                                                */


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

bool IsCoolWord(std::string &roWord) {
	std::map<char, int> oCharMap;
//	for (auto &c : roWord)
//		roCharMap[c]++;
	for (std::string::iterator oIt = roWord.begin(); oIt != roWord.end(); oIt++)
		oCharMap[*oIt]++;

	if (oCharMap.size() < 2)
		return false;

	std::set<int> oFreqSet;
	for (std::map<char, int>::iterator oIt = oCharMap.begin(); oIt != oCharMap.end(); oIt++)
		oFreqSet.insert(oIt->second);

	return oFreqSet.size() == oCharMap.size();
} 

int main() {
	int nCaseNumber = 1;

	while (true) {
		int nNoWords;
		string oLine;
		getline(cin, oLine);
		if (!oLine.size())
			return 0;
		stringstream oStream(oLine);
		oStream >> nNoWords;

		int nNoNiceWords = 0;
		for (int nWordLoop = 0; nWordLoop < nNoWords; nWordLoop++) {
			getline(cin, oLine);
			if (IsCoolWord(oLine))
				nNoNiceWords++;
		}

		std::cout << "Case " << nCaseNumber << ": " << nNoNiceWords << std::endl;

		nCaseNumber++;
	}

	return 0;
}