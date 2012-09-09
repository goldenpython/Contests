/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10344 - 23 out of 5                                              */



#include <stdio.h>

int g_arrnNumbers[5];
int g_arrnUsed[5];

#define INLINE __inline

INLINE int PerformOp(int nOp, int nLHS, int nRHS) {
	switch (nOp) {
		case '+':
			return nLHS + nRHS;
		
		case '-':
			return nLHS - nRHS;

		case '*':
			return nLHS * nRHS;
	}
}

int bk(int nStep, int nLastOp, int nResult) {
	int nLoop, nRetValue;

	if (nStep == 9) {
		return nResult == 23 ? 1 : 0;
	}

	if (nStep % 2) {
		return bk(nStep + 1, '+', nResult) || bk(nStep + 1, '-', nResult) || bk(nStep + 1, '*', nResult);
	} else {
		for (nLoop = 0; nLoop < 5; nLoop++)
			if (!g_arrnUsed[nLoop]) {
				g_arrnUsed[nLoop] = 1;
				nRetValue = bk(nStep + 1, nLastOp, PerformOp(nLastOp, nResult, g_arrnNumbers[nLoop]));
				g_arrnUsed[nLoop] = 0;

				if (nRetValue)
					return 1;
			}

		return 0;
	}
}

int main() {
	while	(
				scanf("%d %d %d %d %d", &g_arrnNumbers[0], &g_arrnNumbers[1], &g_arrnNumbers[2], &g_arrnNumbers[3], &g_arrnNumbers[4]) &&
				g_arrnNumbers[0] && g_arrnNumbers[1] && g_arrnNumbers[2] && g_arrnNumbers[3] && g_arrnNumbers[4]
			) {
		printf(bk(0, '+', 0) ? "Possible\n" : "Impossible\n");
	}

	return 0;
}
