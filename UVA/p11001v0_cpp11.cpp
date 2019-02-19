/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11001 - Necklace                                                 */


#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// function from : https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x-y) <= std::numeric_limits<T>::epsilon() * std::abs(x+y) * ulp
        // unless the result is subnormal
        || std::abs(x-y) < std::numeric_limits<T>::min();
}

int main() {
	for (int nVTotal, nV0; (cin >> nVTotal >> nV0) && nVTotal && nV0; ) {
		auto lfMaxNecklaceLength = -1.0;
		auto nMaxDisks = 0;
		for (int nNoDisks = 1; ; nNoDisks++) {
			auto lfDiskV = static_cast<double>(nVTotal) / nNoDisks;
			if (lfDiskV <= nV0)
				break;
				
			auto lfDiskD = 0.3 * sqrt(lfDiskV - nV0);
			auto lfCurrentNecklaceLen = lfDiskD * nNoDisks;
			if (almost_equal(lfMaxNecklaceLength, lfCurrentNecklaceLen, 1)) {
				nMaxDisks = 0;
			} else if (lfMaxNecklaceLength < lfCurrentNecklaceLen) {
				nMaxDisks = nNoDisks;
				lfMaxNecklaceLength = lfCurrentNecklaceLen;
			}
		}
		
		cout << nMaxDisks << endl;
	}
	
	return 0;
}
