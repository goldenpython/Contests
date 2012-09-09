/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 895 - Word Problem                                               */


#include <stdio.h>
#include <string.h>

#define MAX_WORDS		1024
#define MAX_WORD_SIZE	16

char Dict[MAX_WORDS][MAX_WORD_SIZE];
char szLine[MAX_WORD_SIZE];
char Letters[MAX_WORD_SIZE];
char szSol[MAX_WORD_SIZE];
int WordUsed[MAX_WORDS], WordUsageBackup[MAX_WORDS];
int iNoWords, iSol, iNoLetters, iMaxWordLen, iMaxStep;
int Start[256], Start1[256];

int FindWord(char *szWord) {
	int i = Start1[*szWord], j = Start1[*szWord + 1] - 1, mid;
	
	if (Start[*szWord] == -1)
		return -1;
		
	while (i <= j)
		if (strcmp(Dict[mid = (i + j) >> 1] + 1, szWord + 1) < 0)
			i = mid + 1;
		else
			j = mid - 1;
			
	return !strcmp(Dict[i], szWord) ? i : -1;
}

void bk(int step) {
	char repl;
	int i, index;
	
	if (step == iMaxStep)
		return;
		
	szSol[step] = '\0';
	if ((index = FindWord(szSol)) != -1) {
		if (!WordUsed[index]) {
			iSol += WordUsageBackup[index];
			WordUsed[index] = 1;
			
			/* printf("%s|%d\n", Dict[index], index); */
		} else
			return;
	}
	
	for (i = 0; i < iNoLetters; i++) {
		if (Letters[i] != '0') {
			repl = Letters[i];
			szSol[step] = Letters[i];
			Letters[i] = '\0';
			
			bk(step + 1);
			
			Letters[i] = repl;
		}
	}
}

int main() {
	char *p;
	char szLastWord[MAX_WORD_SIZE];
	int len, i;
		
	/* freopen("input/895.txt", "rt", stdin); */
	
	iMaxWordLen = MAX_WORD_SIZE;
	
	for (i = 'a'; i <= 'z'; i++)
		Start[i] = -1;
	
	while (gets(Dict[iNoWords]), *Dict[iNoWords] != '#') {
		if (!iNoWords || strcmp(Dict[iNoWords - 1], Dict[iNoWords])) {
			WordUsageBackup[iNoWords++] = 1;
		
			len = strlen(Dict[iNoWords]);
			if (len > iMaxWordLen)
				iMaxWordLen = len;
		} else
			WordUsageBackup[iNoWords - 1]++;
	}
	
	for (i = 0; i < iNoWords; i++)
		if (Start[*Dict[i]] == -1)
			Start[*Dict[i]] = i;
			
	for (i = 'a'; i <= 'z'; i++)
		if (Start[i] != -1)
			Start1[i] = Start[i];
		else
			Start1[i] = Start[i - 1];
			
	Start1['z' + 1] = iNoWords;
		
	while (gets(szLine), *szLine != '#') {
		iNoLetters = 0;
		for (p = szLine; *p; p++)
			if (*p != ' ')
				Letters[iNoLetters++] = *p;
				
		iMaxStep = iNoLetters < iMaxWordLen ? iNoLetters + 1 : iMaxWordLen + 1;
		
		memset(WordUsed, 0, iNoWords * sizeof(int));
		
		iSol = 0;
		bk(0);
				
		printf("%d\n", iSol);
	}
	
	/* for (;;); */
	
	return 0;
}
