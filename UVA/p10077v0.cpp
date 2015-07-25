/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10077 - The Stern-Brocot Number System                           */


#include <iostream>

int main() {
	int nN, nM;

	while ((std::cin >> nN >> nM), nN > 1 || nM > 1) {
		while (nN > 1 || nM > 1) {
			if (nN > nM) {
				std::cout << "R";
				nN -= nM;
			} else {
				std::cout << "L";
				nM -= nN;
			}
		}

		std::cout << std::endl;
	}

	return 0;
}