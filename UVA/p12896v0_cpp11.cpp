/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12896 - Mobile SMS                                               */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // ONLINE_JUDGE
	 
template <typename T>
static istream& operator >> (istream &roStream, vector<T> &roVector) {
	#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		for (T &oElem : roVector) {
			roStream >> oElem;
		}
	#else
		for_each(roVector.begin(), roVector.end(), [&roStream](T &roElem) { roStream >> roElem; });
	#endif

	return roStream;
}

int main() {
	vector<string> oVecKeysChars;
	oVecKeysChars.push_back(" ");
	oVecKeysChars.push_back(".,?\"");
	oVecKeysChars.push_back("abc");
	oVecKeysChars.push_back("def");
	oVecKeysChars.push_back("ghi");
	oVecKeysChars.push_back("jkl");
	oVecKeysChars.push_back("mno");
	oVecKeysChars.push_back("pqrs");
	oVecKeysChars.push_back("tuv");
	oVecKeysChars.push_back("wxyz");

	int nNoCases;

	cin >> nNoCases;

	while (nNoCases--) {
		int nNoChars;
		cin >> nNoChars;

		vector<int> oVecKeys(nNoChars), oVecNoTimesKeyWasPressed(nNoChars);
		cin >> oVecKeys >> oVecNoTimesKeyWasPressed;

		for (int nLoop = 0; nLoop < nNoChars; nLoop++)
			cout << oVecKeysChars[oVecKeys[nLoop]][oVecNoTimesKeyWasPressed[nLoop] - 1];

		cout << endl;
	}

	return 0;
}