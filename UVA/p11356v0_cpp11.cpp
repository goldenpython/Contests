/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11356 - Dates                                                    */


#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		struct tm oTime = { 0 };
		const auto pszDateFormatSpecifier = "%Y-%B-%d";
		cin >> get_time(&oTime, pszDateFormatSpecifier);

		int nK;
		cin >> nK;
		oTime.tm_mday += nK;
		mktime(&oTime);
		cout << "Case " << nCaseLoop << ": " << put_time(&oTime, pszDateFormatSpecifier) << endl;
	}

	return 0;
}