/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 621 - Secret Research                                            */


#include <iostream>
#include <string>

using namespace std;

int main() {
	int nNoCases;

	for (cin >> nNoCases; nNoCases--; ) {
		string sNumber;

		cin >> sNumber;

		if (sNumber == "1" || sNumber == "4" || sNumber == "78")
			cout << "+\n";
		else if (sNumber.substr(sNumber.size() - 2) == "35")
			cout << "-\n";
		else if (sNumber.size() > 2 && sNumber[0] == '9' && sNumber[sNumber.size() - 1] == '4')
			cout << "*\n";
		else if (sNumber.substr(0, 3) == "190")
			cout << "?\n";
	}

	return 0;
}