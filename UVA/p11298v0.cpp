/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11298 - Dissecting a Hexagon                                     */

#include <stdio.h>

int main() {
	for (int nN; scanf("%d", &nN) ; printf((nN > 2 && !(nN % 3)) ? "1\n" : "0\n"))
		;

	return 0;
}