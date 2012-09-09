/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 991 - Safe Salutations                                           */


#include <stdio.h> 

int main() { 
	int n, i, j; 
	int arr[20]; 
	char szLine[50];

	arr[0] = 0; 
	arr[1] = 1; 
	arr[2] = 2; 

	for(i = 3; i <= 10; i++) 
	{ 
		arr[i] = arr[i - 1] * 2;

		for (j = 1; j < i - 1; j++)
			arr[i] += arr[j] * arr[i - j - 1];
	} 

	j = 0;
	while(gets(szLine)) {
		if (!*szLine)
			continue;

		n = atoi(szLine);

		if (j)
			printf("\n");
		printf("%d\n", arr[n]), j++; 
	}

	return 0; 
} 
