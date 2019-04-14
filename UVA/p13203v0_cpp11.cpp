/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13203 - Disk Madness                                             */



// we can place the disks such that their centers lay on a single line and each i-th circle contains all 
// the previous i-1 ones except the last one.

#include <iostream>

int main() {
	for (int nN; std::cin >> nN; )
		std::cout << (nN - 1LL) * (nN - 2) / 2 << std::endl;

	return 0;
}