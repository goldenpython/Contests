/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 847 - A Multiplication Game                                      */


#include <iostream>

using namespace std;

bool FirstWins(long long llP, long long llN) {
	if (llP * 9 >= llN)
		return true;
	else if (llP * 2 < llN && llP * 18 >= llN)
		return false;

	for (int nLoop = 2; nLoop <= 9; nLoop++)
		if (!FirstWins(nLoop * llP, llN))
			return true;

	return false;
}

int main() {
	for (long long llN; cin >> llN; )
		cout << (FirstWins(1, llN) ? "Stan wins." : "Ollie wins.") << endl;

	return 0;
}