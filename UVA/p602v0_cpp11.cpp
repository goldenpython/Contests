/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 602 - What Day Is It?                                            */


#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

bool IsLeapYear(int nYear) {
	if (nYear > 1752)
		return !(nYear % 4) && (nYear % 100) || !(nYear % 400);
	else
		return !(nYear % 4);
}

bool DateIsValid(int nDay, int nMonth, int nYear) {
	if (nDay < 1 || nMonth < 1 || nMonth > 12 || nYear < 1)
		return false;

	if (nYear == 1752 && nMonth == 9 && (nDay > 2 && nDay < 14))
		return false;

	if (nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11)
		return nDay <= 30;

	if (nMonth == 2)
		return nDay <= (IsLeapYear(nYear) ? 29 : 28);

	return nDay <= 31;
}

using namespace std;

#define USE_PUTTIME

int main() {
#ifndef USE_PUTTIME
    vector<string> oVecDayName = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<string> oVecMonthName = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
#endif // USE_PUTTIME

	int nDay, nMonth, nYear;
	while ((cin >> nMonth >> nDay >> nYear) && (nDay || nMonth || nYear)) {
		if (!DateIsValid(nDay, nMonth, nYear)) {
			cout << nMonth << '/' << nDay << '/' << nYear << " is an invalid date." << endl;
			continue;
		}

		struct tm oTime = { 0 };
		oTime.tm_mday = 1;
		oTime.tm_mon = nMonth - 1;
		oTime.tm_year = nYear - 1900 + 7 * 400;
		mktime(&oTime);
#ifdef USE_PUTTIME
		cout << put_time(&oTime, "%B ") << nDay << ", " << nYear << " is a ";
#else
        cout << oVecMonthName[nMonth - 1] << ' ' << nDay << ", " << nYear << " is a ";
#endif // USE_PUTTIME

		oTime.tm_mday = nDay;

		int nDiff = 0;
		if (nYear < 1752)
			for (int nYearLoop = (nYear + 99) / 100 * 100; nYearLoop <= 1700; nYearLoop += 100)
				if (nYearLoop % 400 && !(nYear == nYearLoop && nMonth > 2))
					nDiff++;

		if (nYear < 1752 || (nYear == 1752 && (nMonth < 9 || (nMonth == 9 && nDay <= 2))))
			oTime.tm_mday += 11 - nDiff;

		mktime(&oTime);
#ifdef USE_PUTTIME
		std::cout << put_time(&oTime, "%A") << endl;
#else
        cout << oVecDayName[oTime.tm_wday] << endl;
#endif // USE_PUTTIME
	};

	return 0;
}
