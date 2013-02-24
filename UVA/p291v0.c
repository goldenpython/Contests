/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 291 - The House Of Santa Claus                                   */


#include <stdio.h>

#define NUM_NODES	(sizeof(g_arr2Graph) / sizeof(g_arr2Graph[0]))

int g_arr2Graph[5][5] = {
	{0, 1, 1, 0, 1},
	{1, 0, 1, 0, 1},
	{1, 1, 0, 1, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0},
};


int g_arrSol[9];

void bk(int nStep) {
	int nLoop;

	if (nStep == 9) {
		for (nLoop = 0; nLoop <= 8; nLoop++)
			printf("%d", g_arrSol[nLoop] + 1);
		printf("\n");
	} else {
		for (nLoop = 0; nLoop < NUM_NODES; nLoop++) {
			if(g_arr2Graph[g_arrSol[nStep - 1]][nLoop]) {
				g_arr2Graph[g_arrSol[nStep - 1]][nLoop] = 0;
				g_arr2Graph[nLoop][g_arrSol[nStep - 1]] = 0;
				g_arrSol[nStep] = nLoop;
				bk(nStep + 1);
				g_arr2Graph[g_arrSol[nStep - 1]][nLoop] = 1;
				g_arr2Graph[nLoop][g_arrSol[nStep - 1]] = 1;
			}
		}
	}
}

int main() {
	int nLoop;

	g_arrSol[0] = 0;
	bk(1);

	return 0;
}