/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13275 - Leap Birthdays                                           */


#include <iostream>

bool IsLeapYear(int nYear) {
	if (nYear % 400 == 0) return true;
	else if(nYear % 100 == 0) return false;
	else if(nYear % 4 == 0) return true;
	else return false;
}

int main() {
	int nNoTestCases;
	std::cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nDay, nMonth, nYear, nTargetYear, nResult = 0;
		std::cin >> nDay >> nMonth >> nYear >> nTargetYear;

		if (nDay != 29 || nMonth != 2) {
			nResult = nTargetYear - nYear;
		} else {
			for (nYear++; nYear <= nTargetYear; nResult += IsLeapYear(nYear++))
				;
		}

		std::cout << "Case " << nCaseLoop << ": " << nResult << std::endl;
	}

	return 0;
}