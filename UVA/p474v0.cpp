/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 474 - Heads / Tails Probability                                  */


/*
	1 / (2 ^ n) = x.abcE-y
	log10(1 / (2 ^ n)) = log10(x.abcE-y)  ==>  -n * log10(2) = log10(x.abc * (10 ^ (-y)))
	==>  -n * log10(2) = log10(x.abc) + log10(10 ^ (-y)))
	==>  -n * log10(2) = log10(x.abc) - y
	==>  log10(x.abc) = y - n * log10(2)
	==>  x.abc = 10 ^ (y - n * log10(2))

	Since 0 < x.abc < 10  ==>  0 < y - n * log10(2) < 1  ==>  n * log10(2) < y < 1 + n * log10(2)
	==>  y = int(1 + n * log10(2))
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	for (int nN; cin >> nN; ) {
		double lfLog10 = nN * log10(2);
		int nY = 1 + lfLog10;
		double lfBase = pow(10, nY - lfLog10) - 1E-10;
		cout << "2^" << "-" << nN << " = " << setprecision(3) << fixed << lfBase << "e-" << nY << endl;
	}

	return 0;
}