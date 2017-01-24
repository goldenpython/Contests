/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10101 - Bangla Numbers                                           */


#include <iostream>
#include <iomanip>

void Solve(long long llNumber) {
	const int KUTI = 10000000;
	const int LAKH = 100000;
	const int HAJAR = 1000;
	const int SHATA = 100;

	if (llNumber >= KUTI) {
		Solve(llNumber / KUTI);
		std::cout << " kuti";
		Solve(llNumber %= KUTI);
	} else if (llNumber >= LAKH) {
		Solve(llNumber / LAKH);
		std::cout << " lakh";
		Solve(llNumber %= LAKH);
	} else if (llNumber >= HAJAR) {
		Solve(llNumber / HAJAR);
		std::cout << " hajar";
		Solve(llNumber %= HAJAR);
	} else if (llNumber >= SHATA) {
		Solve(llNumber / SHATA);
		std::cout << " shata";
		Solve(llNumber %= SHATA);
	} else if (llNumber > 0) {
		std::cout << " " << llNumber;
	}
}

int main() {
	long long llNumber;
	for (int nCaseLoop = 1; std::cin >> llNumber; nCaseLoop++) {
		std::cout << std::setw(4) << nCaseLoop << ".";
		if (!llNumber) 
			std::cout << " 0"; 
		else
			Solve(llNumber);
		std::cout << std::endl;
	}
	return 0;
}