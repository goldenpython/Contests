/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10689 - Yet another Number Sequence                              */


#include <stdio.h>
#include <string.h>


int main() {
	int nrcases, loop, i, a, b, c, n, m, fib1, fib2;
	int fib[15001];
	char *p, szLine[100];

	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= 15000; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 10000;


	/* scanf("%d", &nrcases); */
	gets(szLine);
	nrcases = atoi(szLine);

	for (loop = 0; loop < nrcases; loop++) {
		/* scanf("%d %d %d %d", &a, &b, &n, &m); */
		gets(szLine);
		p = strtok(szLine, " ");
		a = atoi(p);
		p = strtok(NULL, " ");
		b = atoi(p);
		p = strtok(NULL, " ");
		n = atoi(p);
		p = strtok(NULL, " ");
		m = atoi(p);

		if (m == 1)
			m = 10;
		else if (m == 2)
			m = 100;
		else if (m == 3)
			m = 1000;
		else if (m == 4)
			m = 10000;

		if (n == 0)
			printf("%d\n", a % m);
		else if (n == 1)
			printf("%d\n", b % m);
		else {
			n--;
			fib1 = (fib[n % 60] % 10) + 10 * ((fib[n % 300] / 10) % 10) + 100 * ((fib[n % 1500] / 100) % 10) +  + 1000 * ((fib[n % 15000] / 1000) % 10);
			n++;
			fib2 = (fib[n % 60] % 10) + 10 * ((fib[n % 300] / 10) % 10) + 100 * ((fib[n % 1500] / 100) % 10) +  + 1000 * ((fib[n % 15000] / 1000) % 10);

			a = (a * fib1 + b * fib2) % m;

			printf("%d\n", a % m);
		}
	}
}
