/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11309 - Counting Chaos                                           */



#include <stdio.h>
#include <string.h>

struct PAL{
	int hh, mm, id;
	char string[6];
};

int num;
struct PAL array[128];

int IsPalindrome(char *s) {
	char *p1 = s, *p2 = s + strlen(s) - 1;
	
	while (p1 <= p2) {
		if (*p1 != *p2)
			return 0;
			
		p1++; p2--;
	}
			
	return 1;
}

void Compute() {
	int h, m;
	char aux[16];
	
	num = 0;
	
	for (h = 0; h < 24; h++)
		for (m = 0; m < 60; m++) {
			if (h)
				sprintf(aux, "%d%02d", h, m);
			else
				sprintf(aux, "%d", m);
				
			if (IsPalindrome(aux)) {
				array[num].hh = h;
				array[num].mm = m;
				sprintf(array[num].string, "%02d:%02d", h, m);
				array[num].id = h * 60 + m;
				num++;
			}
		}
		
	return;
}

int main() {
	int n, i, h, m, p, q, mid, id;
	char szLine[256];
	
	Compute();
	
	gets(szLine); sscanf(szLine, "%d", &n);
	
	for (i = 0; i < n; i++) {
		gets(szLine);
		
		h = (szLine[0] - '0') * 10 + szLine[1] - '0';
		m = (szLine[3] - '0') * 10 + szLine[4] - '0';		
		
		id = h * 60 + m;
		
		p = 0; q = num - 1;
		while (p <= q)
			if (array[mid = (p + q) >> 1].id > id)
				q = mid - 1;
			else
				p = mid + 1;
				
		/* printf("%s %s %d %d\n", array[p].string, array[q].string, p, q); */
		
		printf("%s\n", array[p % num].string);
	}
	
	return 0;
}
