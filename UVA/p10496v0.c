/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10496 - Collecting Beepers                                       */


#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 12
#define LARGE 0xFFFFFF

#define DIST(x1, y1, x2, y2) (fabs(x1 - x2) + fabs(y1 - y2))

int w, h, nbeepers;
int startx, starty;
int posx[MAX], posy[MAX];
int sum, summin;
int used[MAX], sol[MAX];

void ReadData() {
	int i;

	scanf("%d %d", &posx[0], &posy[0]);
	scanf("%d %d", &posx[0], &posy[0]);
	scanf("%d", &nbeepers);

	for (i = 1; i <= nbeepers; i++)
		scanf("%d %d", &posx[i], &posy[i]);
}

void bk(int step, int sum) {
	int i;

	if (sum > summin)
		return;

	if (step == nbeepers + 1) {
		sum += DIST(posx[0], posy[0], posx[sol[nbeepers]], posy[sol[nbeepers]]);
		if (sum < summin)
			summin = sum;
	}

	for (i = 1; i <= nbeepers; i++) 
		if (!used[i]) {
			used[i] = 1;
			sol[step] = i;

			bk(step + 1, sum + DIST(posx[sol[step - 1]], posy[sol[step - 1]], posx[sol[step]], posy[sol[step]]));
			used[i] = 0;
		}
}

void Solve() {
	memset(used, 0, sizeof(used));
	used[0] = 1;
	sol[0] = 0;
	summin = (!nbeepers ? 0 : LARGE);

	bk(1, 0);

	printf("The shortest path has length %d\n", summin);
}

int main() {
	int nrcases, i;

	/*freopen("1.txt", "rt", stdin);  */

	scanf("%d", &nrcases);

	for (i = 0; i < nrcases; i++) {
		ReadData();
		Solve();
	}
}
