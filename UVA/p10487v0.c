/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10487 - Closest Sums                                             */



#include <stdio.h>

#define ABS(a)		((a) > 0 ? (a) : -(a))

#define MAX			1001
#define ARRAY_LEN	((MAX) * (MAX - 1) / 2)

int NoSums;
int *SortPointer;
int Nums[MAX];
int Sums[ARRAY_LEN];

int AtoI(char *szString) {
	int sgn = 1, ret = 0;

	if (*szString == '-') {
		sgn = -1;
		szString++;
	} /* else if (*szString == '+')
		szString++; */

	while (*szString) {
		ret = ret * 10 + *szString++ - '0';
	}

	return ret * sgn;
}

void qsort(int lo, int hi) {
	int i = lo, j = hi;
	int mid = SortPointer[(i + j) >> 1];

	while (i <= j) {
		while (SortPointer[i] < mid)
			i++;

		while (SortPointer[j] > mid)
			j--;

		if (i <= j) {
			int aux = SortPointer[i];
			SortPointer[i] = SortPointer[j];
			SortPointer[j] = aux;

			i++; j--;
		}
	}

	if (i < hi)
		qsort(i, hi);

	if (j > lo)
		qsort(lo, j);
}

int main() {
	int n, m, lim, i, j, nr, sol, i1, i2, mid, CaseNo = 1;
	char szLine[128];

/*
	freopen("input//10487.txt", "rt", stdin);
*/

	while (gets(szLine), n = AtoI(szLine)) {
		for (i = 0; i < n; i++) {
			gets(szLine);
			Nums[i] = AtoI(szLine);
		}

		SortPointer = Nums;
		qsort(0, n - 1);

		NoSums = 0;
		for (i = 0; i < n; i++) {
			lim = ((n - i - 1) & ~0x7);
			for (j = i + 1; j < lim; ) {
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
				Sums[NoSums++] = Nums[i] + Nums[j++];
			}

			for ( ; j < n; j++)
				Sums[NoSums++] = Nums[i] + Nums[j];
		}

		SortPointer = Sums;
		qsort(0, NoSums - 1);

		gets(szLine);
		m = AtoI(szLine);

		printf("Case %d:\n", CaseNo);

		for (i = 0; i < m; i++) {
			gets(szLine);
			nr = AtoI(szLine);

			i1 = 0; i2 = NoSums - 1;
			while (i1 <= i2) {
				if (Sums[mid = (i1 + i2) >> 1] > nr)
					i2 = mid - 1;
				else
					i1 = mid + 1;
			}

			if (i2 >= 0) {
				sol = Sums[i2];
				if (i2 < NoSums - 1 && ABS(Sums[i2 + 1] - nr) < ABS(sol - nr))
					sol = Sums[i2 + 1];
			} else
				sol = Sums[i2 + 1];

			printf("Closest sum to %d is %d.\n", nr, sol);
		}

		CaseNo++;
	}



	return 0;
}
