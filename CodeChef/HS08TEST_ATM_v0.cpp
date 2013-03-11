/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem ATM / HS08TEST                                                   */


#include <stdio.h>

int main() {
	int nX;
	float fY;

	scanf("%d %f", &nX, &fY);
	if (!(nX % 5) && nX + 0.5f <= fY)
		fY -= nX + 0.5f;

	printf("%0.2f", fY);

	return 0;
}