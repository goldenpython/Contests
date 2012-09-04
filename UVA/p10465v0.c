/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10465 - Homer Simpson                                            */



#include <stdio.h>
#include <string.h>

#define MAX 10010

int main() {
	int n, m, total;
	int sol[MAX];
	int i, pos;

	while (scanf("%d %d %d", &n, &m, &total) == 3) {
		memset(sol, 0, sizeof(sol));
		
		sol[0] = 1;

		for (i = 0; i < total; i++)
			if (sol[i]) {
				pos = i + n;				
				if (pos <= total && sol[pos] < sol[i] + 1)
					sol[pos] = sol[i] + 1;

				pos = i + m;				
				if (pos <= total && sol[pos] < sol[i] + 1)
					sol[pos] = sol[i] + 1;
			}

		for (i = total; !sol[i]; i--);
		printf("%d", sol[i] - 1);
		if (i != total)
			printf(" %d", total - i);
		printf("\n");
	}
}
