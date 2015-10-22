/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 893 - Y3K Problem                                                */


#include <iostream>

using namespace std;

bool IsLeapYear(int nYear) {
	return !(nYear % 4) && (nYear % 100) || !(nYear % 400);
}

int GetDaysInYear(int nYear) {
	return IsLeapYear(nYear) ? 366 : 365;
}

int GetDaysInMonth(int nMonth, int nYear) {
	switch (nMonth) {
		case 1:
			return 31;
		case 2:
			return IsLeapYear(nYear) ? 29 : 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
}

int main() {
	int nDays, nD, nM, nY;
	while ((cin >> nDays >> nD >> nM >> nY), nD) {
		if (nD > 28) {
			int nDiff = nD - 28;
			nDays += nDiff;
			nD = 28;
		}

		while (true) {
			int nDaysInYear = GetDaysInYear(nM <= 2 ? nY : nY + 1);
			if (nDays < nDaysInYear)
				break;

			nDays -= nDaysInYear;
			nY++;
		}

		while (true) {
			int nDaysInMonth = GetDaysInMonth(nM, nY);
			if (nDays < nDaysInMonth)
				break;

			nDays -= nDaysInMonth;
			nM++;
			if (nM > 12) {
				nM = 1;
				nY++;
			}
		}

		nD += nDays;
		int nDaysInMonth = GetDaysInMonth(nM, nY);
		if (nD > nDaysInMonth) {
			nD -= nDaysInMonth;
			nM++;
		}

		if (nM > 12) {
			nM = 1;
			nY++;
		}


		cout << nD << " " << nM << " " << nY << endl;
	}

	return 0;
}