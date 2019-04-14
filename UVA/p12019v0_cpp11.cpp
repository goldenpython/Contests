/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12019 - Doom's Day Algorithm                                     */


#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nMonth, nDay;
		cin >> nMonth >> nDay;

		struct tm oTime = { 0 };
		oTime.tm_year = 2011 - 1900;
		oTime.tm_mon = nMonth - 1;
		oTime.tm_mday = nDay;
		mktime(&oTime);

		cout << put_time(&oTime, "%A") << endl;
	}

	return 0;
}