/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12791 - Lap                                                      */


#include <iostream>

int main() {
	int nT1, nT2;
	while (std::cin >> nT1 >> nT2) {
		int nDiff = nT2 - nT1;
		int nMod = nT1 % nDiff;
		std::cout << nT1 / nDiff + (nMod ? 2 : 1) << std::endl;
	}
	return 0;
}

/*
	L = length of a lap
	D1 = D2 + L	(distance covered by each driver until driver1 overtakes driver2)
	D1 / T = L / t1, D2 / T = L / t2
	=> T = D1 * t1 / L, T = D2 * t2 / L
	D1 * t1 = D2 * t2 => (D2 + L) * t1 = D2 * t2 => D2 / L * (t1 - t2) + t1 = 0
	let X = D2 / L (number of laps driver2 completes until it is passed by driver1)
	X = t1 / (t2 - t1)
	The solution is ceil(X + 1)
*/