/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 498 - Polly the Polynomial                                       */


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

template<typename T, typename TSTREAM>
void ReadArray(TSTREAM &roStream, std::vector<T> &roNumbersArray) {
	for(T oElement; roStream >> oElement; )
		roNumbersArray.emplace_back(oElement);
}

template<typename T>
void ReadArrayFromLine(std::string oLine, std::vector<T> &roNumbersArray) {
	std::stringstream oStringStream(oLine);
	ReadArray(oStringStream, roNumbersArray);
}

using namespace std;


int main() {
	for (string oLine; getline(cin, oLine); ) {
		vector<long long> oVecllCoeff, oVecllXValues;

		ReadArrayFromLine(oLine, oVecllCoeff);
		reverse(oVecllCoeff.begin(), oVecllCoeff.end());
		
		getline(cin, oLine);
		ReadArrayFromLine(oLine, oVecllXValues);

		vector<long long> oVecllPowers(oVecllXValues.size(), 1), oVecllValues(oVecllXValues.size(), 0);

		for (auto oItCoeff = oVecllCoeff.cbegin(); oItCoeff != oVecllCoeff.cend(); ++oItCoeff) {
			vector<long long> oVecllTemp(oVecllXValues.size(), *oItCoeff);
			transform(oVecllTemp.cbegin(), oVecllTemp.cend(), oVecllPowers.cbegin(), oVecllTemp.begin(), multiplies<long long>());
			transform(oVecllTemp.cbegin(), oVecllTemp.cend(), oVecllValues.cbegin(), oVecllValues.begin(), plus<long long>());
			transform(oVecllPowers.cbegin(), oVecllPowers.cend(), oVecllXValues.cbegin(), oVecllPowers.begin(), multiplies<long long>());
		}

		cout << oVecllValues[0];
		for (auto oItValue = next(oVecllValues.cbegin()); oItValue != oVecllValues.cend(); ++oItValue)
			cout << ' ' << *oItValue;
		cout << endl;
	}

	return 0;
}