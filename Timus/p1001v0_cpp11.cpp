/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1001. Reverse Root                                               */
/*   http://acm.timus.ru/problem.aspx?num=1001                                */


#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

int main() {
	std::vector<long long> oVecNumbers;
	long long nNumber;
	while (std::cin >> nNumber)
		oVecNumbers.push_back(nNumber);
	for (auto oIt = oVecNumbers.crbegin(); oIt != oVecNumbers.crend(); oIt++)
		std::cout << std::fixed << std::setprecision(4) << std::sqrt(static_cast<double>(*oIt)) << std::endl;

	return 0;
}