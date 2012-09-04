/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10579 - Fibonacci Numbers                                        */


#include <stdio.h>

#define MAX(a,b)  ((a) > (b) ? (a) : (b))

#define MAXL 1005
#define MAXN 5000


int n;
char fib[MAXN][MAXL];
int nrc[MAXN];

void add(int lin) 
{
	int l1 = lin - 1, l2 = lin - 2, c = MAX(nrc[l1], nrc[l2]);

	char r = 0;
	for (int i = 0; i < c; i++) {
		r += fib[l1][i] + fib[l2][i];
		fib[lin][i] = r % 10;
		r /= 10;
	}

	nrc[lin] = c;
	if (r)
		fib[lin][nrc[lin]++] = 1;
}

void gen() 
{
	fib[1][0] = fib[2][0] = nrc[1] = nrc[2] = 1;

	for (int i = 3; nrc[i - 1] < MAXL; i++) 
		add(i);
}

int main() 
{
	gen();

	while (scanf("%d", &n) == 1) {
		for (int i = nrc[n] - 1; i >= 0; i--)
			printf("%d", fib[n][i]);
		printf("\n");
	}

	return 0;
}
