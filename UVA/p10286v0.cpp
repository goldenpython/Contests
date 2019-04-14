/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10286 - Trouble with a Pentagon                                  */


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double DegreesToRadians(double lfDegrees) {
	const double PI = 3.14159265359;
	return PI * lfDegrees / 180;
}

int main() {
	for (double lfPentagonSideLen; cin >> lfPentagonSideLen; ) {
		// Up-left side triangle has angles of 108, 9, 63
		// Thus, using law of the sines (https://en.wikipedia.org/wiki/Law_of_sines) 
		cout << setprecision(12) << fixed << lfPentagonSideLen *  sin(DegreesToRadians(108)) / sin(DegreesToRadians(63)) << endl;
	}

	return 0;
}