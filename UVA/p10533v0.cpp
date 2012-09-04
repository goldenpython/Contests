/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10533 - Digit Primes                                             */



#include <stdio.h>

#define MAX 1000005

short ip[MAX];

int   primes[90000],
      nrp;
int   prime[100];

void init() {
    int i, j, k, s;

    primes[0] = 2;
    primes[1] = 3;
    nrp = 2;
    prime[2] = 1;
    ip[0] = ip[1] = 0;
    ip[2] = 1;

    for (i = 3; i < MAX; i += 2) {
        ip[i] = ip[i - 1];

        for (j = 1; primes[j] * primes[j] <= i; j++)
            if (!(i % primes[j])) {
                j = -1;

                break;
            }

        if (j != -1) {
            primes[nrp++] = i;

            if (i < 100)
                prime[i] = 1;

            k = i;
            s = 0;

            while (k) {
                s += k % 10;

                k /= 10;
            }

            if (prime[s])
                ip[i]++;
        }

        ip[i + 1] = ip[i];
    }
}

void main() {
    int t1, t2, nri, i;

    init();

    scanf("%d", &nri);

    for (i = 0; i < nri; i++) {
        scanf("%d %d", &t1, &t2);

        printf("%d\n", ip[t2] - ip[t1 - 1]);
    }
}
