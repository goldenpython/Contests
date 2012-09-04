/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10935 - Throwing cards away I                                    */


#include <stdio.h>

#define MAX_ARR_LEN 3000

int main() {
	int n, i, j;
	int arr[MAX_ARR_LEN];

	while (scanf("%d", &n), n) {
		if (n == 1) {
			printf("Discarded cards:\n"); 
			printf("Remaining card: 1\n");
			continue;
		} 

		for (i = 1; i < n; i++)
			arr[i] = i + 1;
		arr[n++] = arr[1];
		j = 2;

		printf("Discarded cards: 1"); 
		while (j < n - 1) {
			printf(", %d", arr[j]);
			arr[n++] = arr[j + 1];
			j += 2;
		}
		printf("\nRemaining card: ");
		printf("%d\n", arr[j]);
	}
}
