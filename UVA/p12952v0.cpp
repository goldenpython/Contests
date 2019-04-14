/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12952 - Tri-du                                                   */


#include <iostream>
#include <algorithm>

int main() {
	for (int nA, nB; std::cin >> nA >> nB; )
		std::cout << (nA == nB ? nA : std::max(nA, nB)) << std::endl;
		
	return 0;
}