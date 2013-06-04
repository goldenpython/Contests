/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 352 - The Seasonal War                                           */


#include <stdio.h>

#define MAX	28

int main() {
	char szLine[MAX];

	int Case = 1;
	while (gets(szLine)) {
		int n;
		sscanf(szLine, "%d", &n);

		char matrix[MAX][MAX];

		for (int i = 1; i <= n; i++) {
			gets(matrix[i] + 1);
			matrix[i][0] = matrix[i][n + 1] = '.';
		}

		for (int i = 1; i <= n; i++)
			matrix[0][i] = matrix[n + 1][i] = '.';

		int Sol = 0;
		for (int ii = 1; ii <= n; ii++)
			for (int jj = 1; jj <= n; jj++)
				if (matrix[ii][jj] == '1') {
					Sol++;

					int qhead, qtail, qi[MAX * MAX], qj[MAX * MAX];
					qhead = qtail = 0;
					qi[qhead] = ii; qj[qhead] = jj;

					matrix[ii][jj] = '0';

					for ( ; qhead <= qtail; qhead++) {
						//const int di[] = {-1, +1, +0, +0, -1, -1, +1, +1};
						//const int dj[] = {+0, +0, -1, +1, +1, -1, +1, -1};
						const int di[] = {-1, -1, -1, +0, +0, +1, +1, +1};
						const int dj[] = {-1, +0, +1, -1, +1, -1, +0, +1};

						for (int k = 0; k < sizeof(di) / sizeof(int); k++) {
							int iii = qi[qhead] + di[k];
							int jjj = qj[qhead] + dj[k];

							if (matrix[iii][jjj] == '1') {
								matrix[iii][jjj] = '0';
								qi[++qtail] = iii;
								qj[qtail] = jjj;
							}
						}
					}


				}



		printf("Image number %d contains %d war eagles.\n", Case, Sol);

		Case++;
	}

	return 0;
}
