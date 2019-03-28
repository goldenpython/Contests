/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10105 - Polynomial Coefficients                                  */


/*
	C(N, n1) * C(N - n1, n2) * C(N - n1 - n2, n3) * ... * C(N - n1 - n2 - n3 - ... , nk) = 
	N! / (N - n1)! / n1!  *  (N - n1)! / (N - n1 - n2)! / n2! * ... = 
	= N! / n1! / n2! / ... / nk!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> oVecnFactorials(13, 1);
	int nIndex = 2, nCurrentFactorial = 1;
	generate(
		next(oVecnFactorials.begin(), 2), 
		oVecnFactorials.end(), 
		[nIndex, nCurrentFactorial] () mutable { return nCurrentFactorial *= nIndex++; } 
	);

	for (int nN, nK, nSol; cin >> nN >> nK; ) {
		for (nSol = oVecnFactorials[nN]; nK--; cin >> nN, nSol /= oVecnFactorials[nN])
			;
		cout << nSol << endl;
	}

	return 0;
}