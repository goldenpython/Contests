/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12750 - Keep Rafa at Chelsea                                     */

#include <iostream>

int main() {
	int nNoTestCases;
	std::cin >> nNoTestCases;

	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoMatches;
		std::cin >> nNoMatches;
		
		int nLastWin = -1;
		for (int nCurrentMatch = 0; nCurrentMatch < nNoMatches; ) {
			char c;
			std::cin >> c;
			switch (c) {
				case 'W':
					if (nLastWin != -2)
						nLastWin = nCurrentMatch;
					nCurrentMatch++;
					break;
				case 'L':
				case 'D':
					if (nLastWin != -2 && nCurrentMatch - nLastWin >= 3) {
						std::cout << "Case " << nCaseLoop << ": " << (nCurrentMatch + 1) << std::endl;
						nLastWin = -2;
					}
					nCurrentMatch++;
					break;
			}
		}

		if (nLastWin != -2)
			std::cout << "Case " << nCaseLoop << ": Yay! Mighty Rafa persists!" << std::endl;
	}

	return 0;
}
