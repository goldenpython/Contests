/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10409 - Die Game                                                 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	char szLine[128];
	int n, i, l, r, t1, t2, t3, t4, aux;

	/* freopen("input/10409.txt", "rt", stdin); */

	while (1) {
		gets(szLine);
		n = atoi(szLine);

		if (!n)
			return 0;

		t1 = 1; t2 = 5; t3 = 6; t4 = 2;
		l = 3; r = 4;

		for (i = 0; i < n; i++) {
			gets(szLine);

			switch(*szLine) {
				case 'n':
					aux = t1;
					t1 = t2; 
					t2 = t3; 
					t3 = t4;
					t4 = aux;
					break;

				case 's':
					aux = t4;
					t4 = t3;
					t3 = t2; 
					t2 = t1; 
					t1 = aux;
					break;

				case 'w':
					aux = t1;
					t1 = r; 
					r = t3; 
					t3 = l;
					l = aux;
					break;

				case 'e':
					aux = t1;
					t1 = l;
					l = t3;
					t3 = r;
					r = aux;
					break;
			}
		}

		printf("%d\n", t1);
	}
	return 0;
}