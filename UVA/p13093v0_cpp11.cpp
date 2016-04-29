/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13093 - Acronyms                                                 */


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string oLineAuthors, oLineName;
	while (getline(cin, oLineAuthors) && getline(cin, oLineName)) {
		stringstream oStreamAuthors(oLineAuthors), oStreamName(oLineName);
		bool bYes = true;
		do {
			string oAuthor, oName;
			bool bAuthorRead = static_cast<bool>(oStreamAuthors >> oAuthor);
			bool bNameRead = static_cast<bool>(oStreamName >> oName);
			if ((bAuthorRead ^ bNameRead) || (bAuthorRead && bNameRead && oAuthor[0] != oName[0])) {
				bYes = false;
				break;
			}
			if (!bAuthorRead && !bNameRead)
				break;
		} while (true);

		cout << (bYes ? "yes" : "no") << endl;
	}
	return 0;
}