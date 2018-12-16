/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13217 - Amazing Function                                         */



// https://www.wolframalpha.com/input/?i=g(0)%3Dsqrt(2)%2Bsqrt(3)%2Bsqrt(6),+g(n%2B1)%3D(g(n)%5E2+-+5)+%2F+(2+*+g(n)+%2B+4)

#define _USE_MATH_DEFINES

#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	for (string oLine; getline(cin, oLine); ) {
		if (oLine.size() > 1)
			oLine = oLine.substr(oLine.size() - 2, 2);
		int nN = stoi(oLine);
		if (nN >= 3)
			nN = 3 + ((1 + nN) % 2);

		cout << setprecision(10) << fixed << 1.0 / tan(M_PI * pow(2.0, nN - 3) / 3) - 2 << endl;
	}

	return 0;
}