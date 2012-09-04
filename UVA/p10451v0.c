/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10451 - Ancient Village Sports                                   */


#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 
int main() {
	int n, nrcase = 0;
	double area, h, l;

	while (1) {
		if (scanf("%d", &n) != 1 || n <= 2)
			return 0;

		scanf("%lf", &area);
		h = sqrt(area / (n * sin (PI / n) / cos(PI / n)));
		l = h / cos(PI / n);
		printf("Case %d: %.5lf %.5lf\n", ++nrcase, PI * l * l - area, area - PI * h * h);

	}
	return 0;
}
