/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 216 - Getting in Line                                            */


#include <stdio.h>
#include <math.h>

const int MAX_POINTS = 8;

int g_nNoPoints;
bool arrbUsed[MAX_POINTS];
double lfCostSol;
int arrnCurrentSol[MAX_POINTS], arrnSol[MAX_POINTS];

double g_arr2lfDist[MAX_POINTS][MAX_POINTS];

void bk(int nStep, double lfCostSoFar) {
	if (lfCostSoFar > lfCostSol)
		return;

	if (nStep == g_nNoPoints) {
		if (lfCostSoFar < lfCostSol) {
			lfCostSol = lfCostSoFar;
			for (int nLoop = 0; nLoop < g_nNoPoints; nLoop++)
				arrnSol[nLoop] = arrnCurrentSol[nLoop];
		}
	} else {
		for (int nLoop = 0; nLoop < g_nNoPoints; nLoop++)
			if (!arrbUsed[nLoop]) {
				arrbUsed[nLoop] = true;
				arrnCurrentSol[nStep] = nLoop;
				bk(nStep + 1, nStep ? lfCostSoFar + g_arr2lfDist[arrnCurrentSol[nStep - 1]][nLoop] : 0.0f);
				arrbUsed[nLoop] = false;
			}
	}
}

int main() {

	int nCase = 1;
	int arrnX[MAX_POINTS], arrnY[MAX_POINTS];

	while (scanf("%d", &g_nNoPoints), g_nNoPoints) {
		for (int nLoop = 0; nLoop < g_nNoPoints; nLoop++)
			scanf("%d %d", &arrnX[nLoop], &arrnY[nLoop]);

		for (int nLoop1 = 0; nLoop1 < g_nNoPoints; nLoop1++) {
			arrbUsed[nLoop1] = false;
			g_arr2lfDist[nLoop1][nLoop1] = 0.0f;
			for (int nLoop2 = nLoop1 + 1; nLoop2 < g_nNoPoints; nLoop2++)
				g_arr2lfDist[nLoop1][nLoop2] = g_arr2lfDist[nLoop2][nLoop1] = 16 + sqrt((double)((arrnX[nLoop1] - arrnX[nLoop2]) * (arrnX[nLoop1] - arrnX[nLoop2]) + (arrnY[nLoop1] - arrnY[nLoop2]) * (arrnY[nLoop1] - arrnY[nLoop2])));
		}

		//arrbUsed[0] = true;
		//arrnCurrentSol[0] = 0;
		lfCostSol = 1E12;
		bk(0, 0.0f);

		printf("**********************************************************\n");
		printf("Network #%d\n", nCase);
		for (int nLoop = 1; nLoop < g_nNoPoints; nLoop++)
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.02lf feet.\n", arrnX[arrnSol[nLoop - 1]], arrnY[arrnSol[nLoop - 1]], arrnX[arrnSol[nLoop]], arrnY[arrnSol[nLoop]], g_arr2lfDist[arrnSol[nLoop - 1]][arrnSol[nLoop]]);
		printf("Number of feet of cable required is %.02lf.\n", lfCostSol);

		nCase++;
	}

	return 0;
}