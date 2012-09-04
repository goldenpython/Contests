/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11152 - Colourful Flowers                                        */


#include <stdio.h>
#include <math.h>

#define PI  3.14159265358979323846 

int main()
{
    int a, b, c;
    double s, v, r, radr, rads;
    double p;  
    
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        p = (a + b + c) / 2.0;
        
        v = sqrt(p * (p - a) * (p - b) * (p - c));
        
        radr = v / p;
        r = PI * radr * radr;

		rads = a * b * c / v / 4;
		s = PI * rads * rads;
		
		s -= v;
		v -= r;
        
        printf("%.4f %.4f %.4f\n", s, v, r);
        

    }
	

    
    return 0;
}
