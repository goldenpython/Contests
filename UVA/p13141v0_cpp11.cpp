/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13141 - Growing Trees                                            */



#include <iostream>

int main() {
	const int MAX = 86;
	long long arrllFib[MAX] = { 0, 1 };
	for (int nLoop = 2; nLoop < MAX; nLoop++)
		arrllFib[nLoop] = arrllFib[nLoop - 1] + arrllFib[nLoop - 2];

	for (int nN; (std::cin >> nN), nN; )
		std::cout << arrllFib[nN] << std::endl;

	return 0;
}