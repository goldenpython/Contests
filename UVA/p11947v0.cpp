/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11947 - Cancer or Scorpio                                        */


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool IsLeapYear(int nYear) {
	return !(nYear % 4) && (nYear % 100) || !(nYear % 400);
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

	return -1;
}

const string GetZodiacSign(int nDay, int nMonth) {
	switch (nMonth) {
		case 1:
			return nDay >= 21 ? "aquarius" : "capricorn";
		case 2:
			return nDay >= 20 ? "pisces" : "aquarius";
		case 3:
			return nDay >= 21 ? "aries" : "pisces";
		case 4:
			return nDay >= 21 ? "taurus" : "aries";
		case 5:
			return nDay >= 22 ? "gemini" : "taurus";
		case 6:
			return nDay >= 22 ? "cancer" : "gemini";
		case 7:
			return nDay >= 23 ? "leo" : "cancer";
		case 8:
			return nDay >= 22 ? "virgo" : "leo";
		case 9:
			return nDay >= 24 ? "libra" : "virgo";
		case 10:
			return nDay >= 24 ? "scorpio" : "libra";
		case 11:
			return nDay >= 23 ? "sagittarius" : "scorpio";
		case 12:
			return nDay >= 23 ? "capricorn" : "sagittarius";
	}

	return "";
}

int main() {
	string oLine;
	getline(cin, oLine);
	stringstream oStringStream(oLine);
	int nNoTestCases;
	oStringStream >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		getline(cin, oLine);
		int nM = (oLine[0] - '0') * 10 + (oLine[1] - '0');
		int nD = (oLine[2] - '0') * 10 + (oLine[3] - '0');
		int nY = (oLine[4] - '0') * 1000 + (oLine[5] - '0') * 100 + (oLine[6] - '0') * 10 + (oLine[7] - '0');

		int nDays = 40 * 7;

		if (nD > 28) {
			int nDiff = nD - 28;
			nDays += nDiff;
			nD = 28;
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

		cout << nCaseLoop << " " << setfill('0') << setw(2) << nM << "/" << setfill('0') << setw(2) << nD << "/" << nY << " " << GetZodiacSign(nD, nM) << endl;
	}

	return 0;
}