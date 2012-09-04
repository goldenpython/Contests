/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10664 - Luggage                                                  */



#include <stdio.h>
#include <string.h>

#define MAX 10000
#define MAXOBJECTS 210

char szLine[MAX];

int n, sum;
int w[MAXOBJECTS];

void ReadLine() {
	char *pl;

	n = sum = 0;
	gets(szLine);
	for (pl = strtok(szLine, " "); pl; pl = strtok(NULL, " ")) {
		sscanf(pl, "%d", &w[n]);
		sum += w[n++];
	}
}

void Solve() {
	int i, j;
	int pd1[MAXOBJECTS], pd2[MAXOBJECTS];

	if (sum % 2) {
		printf("NO\n");
		return;
	}


	memset(pd1, 0, sizeof(pd1));
	memset(pd2, 0, sizeof(pd2));
	pd1[0] = 1; pd2[0] = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < sum; j++)
			if (pd1[j] && j + w[i] <= sum && !pd2[j + w[i]])
				pd2[j + w[i]] = 1;
		memmove(pd1, pd2, sizeof(pd1));
	}

	printf("%s\n", pd2[sum / 2] ? "YES" : "NO");
}

int main() {
	int nrcases, loop;

	 freopen("1.txt", "rt", stdin); 

	gets(szLine);
	sscanf(szLine, "%d", &nrcases);
	for (loop = 0; loop < nrcases; loop++) {
		ReadLine();
		Solve();
	}
}
