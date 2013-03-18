/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem Enormous Input Test / INTEST                                     */


#include <stdio.h>

int main() {
	int nNoTests, nK, nCount = 0;
	
	scanf("%d %d", &nNoTests, &nK);
	for (int nLoop = 0; nLoop < nNoTests; nLoop++) {
		int nNumber;

		scanf("%d", &nNumber);
		if (!(nNumber % nK))
			nCount++;
	}

	printf("%d\n", nCount);

	return 0;
}