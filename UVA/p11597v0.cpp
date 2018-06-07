/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11597 - Spanning Subtree                                         */


/*
	n * (n - 1) / 2 is the number of edges of Kn, n - 1 is the number of edges in a subtree. Thus there can
	be at most n / 2 spanning trees.

	Proof:
		for n = 2, n = 3 the answer is 1 (n/2)

		Let's assume n is even and T(1), T(2), T(n/2) are spanning trees of Kn that have no common edge.
		For n + 1 we have:
			T'(1) = T(1) and vertex (n + 1) connected to vertex 1
			T'(2) = T(2) and vertex (n + 1) connected to vertex 2
			...
			T'(n/2) = T(n/2) and vertex (n + 1) connected with vertex n / 2
			
			(n+1) connected with n/2+1, n/2+1, ..., n are unused edges(not enough to make another spanning tree) 
			thus T'(1) ... T'(n/2) is the maximum set of spanning trees of K(n+1) that have no common edge.

		For n + 2 we have:
			T''(1) = T'(1) and vertex (n + 2) connected to vertex n/2+1 (node of first unused edge in the n+1 solution)
			T''(2) = T'(2) and vertex (n + 2) connected to vertex n/2+2 (node of second unused edge in the n+1 solution)
			...
			T''(n/2) = T'(n/2) and vertex (n + 2) connected with vertex n
			T''(n/2 + 1) = vertex n + 2 connected to 1, 2, 3 .... n/2; vertex n+1 connected to n/2+1, n/2+2, .... n (unused edges in the n+1 solution); n+1 connected ti n+2
			so, for n+2 we found a set of size n/2 + 1.
*/

#include <iostream>

using namespace std;

int main() {
	for (int nCaseLoop = 1, nN; (cin >> nN) && nN; nCaseLoop++)
		cout << "Case " << nCaseLoop << ": " << nN / 2 << endl;

	return 0;
}