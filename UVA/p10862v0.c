/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10862 - Connect the Cable Wires                                  */


#include <stdio.h>
#include <string.h>

#define MAXN		2001
#define MAXC		(1100 >> 2)

#define MAX(a, b)	((a) > (b) ? (a) : (b))

int sol[MAXN][MAXC], sum[MAXN][MAXC];
int nrc[MAXN], nrcs[MAXN];

void ADD(int *nrc1, int *n1, int *nrc2, int *n2) {
	int i, s, r = 0;
	int nrc = MAX(*nrc1, *nrc2);
	
	for (i = 0; i < nrc; i++) {
		s = n1[i] + n2[i] + r;
		n1[i] = s % 1000000000;
		r = s / 1000000000;
	}
	
	if (r)
		n1[(*nrc1)++] = r;
}

int main() {
	int n, i, j;
	
	nrc[0] = 1; sol[0][0] = 1; nrcs[0] = 1; sum[0][0] = 1;
	nrc[1] = 1; sol[1][0] = 1; nrcs[1] = 1; sum[1][0] = 2;
	for (i = 2; i < MAXN; i++) {
		memcpy(sol[i], sol[i - 1], sizeof(int) * nrc[i - 1]);
		nrc[i] = nrc[i - 1];

		ADD(&nrc[i], sol[i], &nrc[i - 1], sol[i - 1]);
		
		ADD(&nrc[i], sol[i], &nrcs[i - 2], sum[i - 2]);

		memcpy(sum[i], sol[i], sizeof(int) * nrc[i]);
		nrcs[i] = nrc[i];
		ADD(&nrcs[i], sum[i], &nrcs[i - 1], sum[i - 1]);		
	}
	
	while (scanf("%d", &n), n) {
		printf("%d", sol[n][nrc[n] - 1]);
		for (i = nrc[n] - 2; i >= 0; i--)
			printf("%09d", sol[n][i]);
		
		printf("\n");			
	}
	
	return 0;
}
