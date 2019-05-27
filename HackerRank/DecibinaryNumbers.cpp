// TimusCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <cassert>
#include <algorithm>




const int SIZE = 19;
template <typename T>
struct A {
	T tTotal;
	T tTotalPartialSum;
	T arrt[SIZE];
	T arrPartialsum[SIZE + 1];
};

static A<long long> arr[286000];
const auto llLIM = static_cast<long long>(pow(10, 16));

using namespace std;

long decibinaryNumbers(long x) {
	static bool bInitialized = false;
	static int nLast;

	if (!bInitialized) {
		bInitialized = true;

		for (int nLoop = 0; nLoop <= 9; nLoop++) {
			arr[nLoop].arrt[0] = 1;
			for (int nPartialSumLoop = 0; nPartialSumLoop < SIZE; nPartialSumLoop++)
				arr[nLoop].arrPartialsum[nPartialSumLoop] = 1;
			arr[nLoop].tTotal = nLoop ? 1 : 0;
			arr[nLoop].tTotalPartialSum = nLoop;
		}

		auto ttTotal = 0LL;

		auto nLoop = 2;
		for (; ttTotal <= llLIM /*nLoop < 1000*/; nLoop++) {
			for (auto nPos = 1; nPos <= SIZE; nPos++) {
				if ((1LL << nPos) > nLoop)
					break;

				for (auto nDigit = 1; nDigit <= 9; nDigit++) {
					auto llValue = nDigit * (1LL << nPos);
					if (llValue > llLIM || nLoop < llValue)
						break;

					arr[nLoop].arrt[nPos] += arr[nLoop - llValue].arrPartialsum[nPos - 1];
					arr[nLoop].tTotal += arr[nLoop - llValue].arrPartialsum[nPos - 1];
				}
			}

			ttTotal -= arr[nLoop].arrPartialsum[SIZE - 1];
			partial_sum(&arr[nLoop].arrt[0], &arr[nLoop].arrt[SIZE], &arr[nLoop].arrPartialsum[0]);
			ttTotal += arr[nLoop].arrPartialsum[SIZE - 1];

			assert(arr[nLoop].tTotal == arr[nLoop].arrPartialsum[SIZE - 1]);

			arr[nLoop].tTotalPartialSum = arr[nLoop - 1].tTotalPartialSum + arr[nLoop - 1].tTotal;
		}

		nLast = nLoop;
	}

	auto llSol = 0LL;

	auto oIt = lower_bound(&arr[0], &arr[nLast], x - 1, [](const A<long long> &lhs, long long rhs) { return lhs.tTotalPartialSum <= rhs; });
	// auto oIt = upper_bound(&arr[0], &arr[nLast], x, [](long long lhs, const A<long long> &rhs) { return rhs.tTotalPartialSum >= lhs; });
	if (oIt->tTotalPartialSum != x)
		--oIt;
	auto nDiff = oIt - &arr[0];
	auto newX = x - oIt->tTotalPartialSum;
	// auto oItNoDigits = lower_bound(&oIt->arrPartialsum[0], &oIt->arrPartialsum[SIZE], newX);

	int nDigitIndex = 0;
	for (int nLoopNoDigit = 0; nLoopNoDigit < SIZE; nLoopNoDigit++) {
		if (arr[nDiff].arrPartialsum[nLoopNoDigit] > newX) {
			nDigitIndex = nLoopNoDigit;
			break;
		}
	}

	int nSol = 0;

	for (;  nDigitIndex >= 0; nDigitIndex--) {

		if (newX >= arr[nDiff].arrPartialsum[nDigitIndex - 1] && (nDiff > 0 || nDigitIndex > 0)) {
			newX -= arr[nDiff].arrPartialsum[nDigitIndex - 1];
		} else {
			nSol *= 10;
			continue;
		}

//		while (arr[nDiff].arrPartialsum[nDigitIndex] <= newX) {
//			newX -= oIt->arrPartialsum[nDigitIndex - 1];
//			nDigitIndex--;
//		}

		int nLoopNoDigit = 1;
		for (; nLoopNoDigit <= 9; nLoopNoDigit++) {
			auto a = nLoopNoDigit * (1 << nDigitIndex);
			if (a >= nDiff /*newx*/) {
				//if (nLoopNoDigit == 1)
				//	nLoopNoDigit = 0;
				break;
			}
			auto newnewX = nDiff - a;
			if (newX >= arr[newnewX].arrPartialsum[nDigitIndex - 1])
				newX -= arr[newnewX].arrPartialsum[nDigitIndex - 1];
			else
				break;
		}

		nSol = nSol * 10 + nLoopNoDigit;

		// auto newXBackup = newX;
		nDiff = nDiff - nLoopNoDigit * (1 << nDigitIndex);
		
		// nDiff = newXBackup;
	}


	return nSol;
}

int main() {


	// decibinaryNumbers(21);
	// decibinaryNumbers(1952951); //  1952951, 3411199, 375
	// decibinaryNumbers(862746); //  862746, 453198, 262
	// decibinaryNumbers(57297); // 57297, 124145, 113
	// decibinaryNumbers(149056);
	// decibinaryNumbers(149057);

	cout << decibinaryNumbers(707954) << endl;
	cout << decibinaryNumbers(711448) << endl;
	cout << decibinaryNumbers(711514) << endl;
	cout << decibinaryNumbers(llLIM) << endl;

	assert(2009790 == decibinaryNumbers(707954));
	assert(11022006 == decibinaryNumbers(711448));
	assert(88799 == decibinaryNumbers(711514));
	assert(900579674 == decibinaryNumbers(llLIM));

    std::cout << "Hello World!\n"; 


	unordered_map<int, vector<long long>> oMap;
	for (auto nLoop = 1; nLoop < 20000000; nLoop++) {
		auto nDeciBinary = 0;
		for (auto nTemp = nLoop, nPow = 1; nTemp > 0; nTemp /= 10, nPow <<= 1) {
			nDeciBinary += nPow * (nTemp % 10);
		}

		oMap[nDeciBinary].push_back(nLoop);
	}


	for (auto nLoop = 1, nIndex = 0; nLoop < 500; nLoop++)
		for (auto nValue : oMap[nLoop])
			cout << ++nIndex << ", " << nValue << ", " << nLoop << endl;

	return 0;
}
