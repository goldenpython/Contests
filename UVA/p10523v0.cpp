/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10523 - Very Easy !!!                                            */



#include <stdio.h>
#include <string.h>

#define MAXC 500

int nr1[MAXC], nr2[MAXC], sum[MAXC];

void prod(int *sir, int nr) 
{
	int r = 0;
	for (int i = 1; i <= sir[0]; i++) {
		r += sir[i] * nr;
		sir[i] = r % 10000;
		r /= 10000;
	}

	while (r) {
		sir[++sir[0]] = r % 10000;
		r /= 10000;
	}
}

void add(int *d, int *s) 
{
	int nrc = d[0];
	if (s[0] > nrc)
		nrc = s[0];

	int r = 0;
	for (int i = 1; i <= nrc; i++) {
		r += s[i] + d[i];
		d[i] = r % 10000;
		r /= 10000;
	}

	if (r) 
		d[++nrc] = r;
	d[0] = nrc;
}

int main() 
{
	int n, a, i;

	while (scanf("%d %d", &n, &a) == 2) {
		memset(nr1, 0, sizeof(nr1));
		memset(nr2, 0, sizeof(nr2));
		memset(sum, 0, sizeof(sum));

		nr1[0] = 1; nr1[1] = 1; sum[0] = 1; sum[1] = 0;
		for (i = 1; i <= n; i++) {
			prod(nr1, a);
			memmove(nr2, nr1, sizeof(nr1));
			prod(nr2, i);
			add(sum, nr2);
		}

		printf("%d", sum[sum[0]]);
		for (i = sum[0] - 1; i; i--)
			printf("%04d", sum[i]);
		printf("\n");
	}

	return 0;
}
