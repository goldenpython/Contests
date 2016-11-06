/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1238. Folding                                                    */
/*   http://acm.timus.ru/problem.aspx?num=1238                                */


#include <stdio.h>
#include <string.h>
#include <string>

static const int arrnNumberSize[] = {
	1	,	//	0
	1	,	//	1
	1	,	//	2
	1	,	//	3
	1	,	//	4
	1	,	//	5
	1	,	//	6
	1	,	//	7
	1	,	//	8
	1	,	//	9
	2	,	//	10
	2	,	//	11
	2	,	//	12
	2	,	//	13
	2	,	//	14
	2	,	//	15
	2	,	//	16
	2	,	//	17
	2	,	//	18
	2	,	//	19
	2	,	//	20
	2	,	//	21
	2	,	//	22
	2	,	//	23
	2	,	//	24
	2	,	//	25
	2	,	//	26
	2	,	//	27
	2	,	//	28
	2	,	//	29
	2	,	//	30
	2	,	//	31
	2	,	//	32
	2	,	//	33
	2	,	//	34
	2	,	//	35
	2	,	//	36
	2	,	//	37
	2	,	//	38
	2	,	//	39
	2	,	//	40
	2	,	//	41
	2	,	//	42
	2	,	//	43
	2	,	//	44
	2	,	//	45
	2	,	//	46
	2	,	//	47
	2	,	//	48
	2	,	//	49
	2	,	//	50
	2	,	//	51
	2	,	//	52
	2	,	//	53
	2	,	//	54
	2	,	//	55
	2	,	//	56
	2	,	//	57
	2	,	//	58
	2	,	//	59
	2	,	//	60
	2	,	//	61
	2	,	//	62
	2	,	//	63
	2	,	//	64
	2	,	//	65
	2	,	//	66
	2	,	//	67
	2	,	//	68
	2	,	//	69
	2	,	//	70
	2	,	//	71
	2	,	//	72
	2	,	//	73
	2	,	//	74
	2	,	//	75
	2	,	//	76
	2	,	//	77
	2	,	//	78
	2	,	//	79
	2	,	//	80
	2	,	//	81
	2	,	//	82
	2	,	//	83
	2	,	//	84
	2	,	//	85
	2	,	//	86
	2	,	//	87
	2	,	//	88
	2	,	//	89
	2	,	//	90
	2	,	//	91
	2	,	//	92
	2	,	//	93
	2	,	//	94
	2	,	//	95
	2	,	//	96
	2	,	//	97
	2	,	//	98
	2	,	//	99
	3	,	//	100
};

static const char arr2nVecDiv[101][12] = {
	{	0,		},			//0
	{	0,		},			//1
	{	0,		},			//2
	{	1,	1	},			//3
	{	2,	1,	2	},			//4
	{	1,	1	},			//5
	{	3,	1,	2,	3	},			//6
	{	1,	1	},			//7
	{	3,	1,	2,	4	},			//8
	{	2,	1,	3	},			//9
	{	3,	1,	2,	5	},			//10
	{	1,	1	},			//11
	{	5,	1,	2,	3,	4,	6	},			//12
	{	1,	1	},			//13
	{	3,	1,	2,	7	},			//14
	{	3,	1,	3,	5	},			//15
	{	4,	1,	2,	4,	8	},			//16
	{	1,	1	},			//17
	{	5,	1,	2,	3,	6,	9	},			//18
	{	1,	1	},			//19
	{	5,	1,	2,	4,	5,	10	},			//20
	{	3,	1,	3,	7	},			//21
	{	3,	1,	2,	11	},			//22
	{	1,	1	},			//23
	{	7,	1,	2,	3,	4,	6,	8,	12	},			//24
	{	2,	1,	5	},			//25
	{	3,	1,	2,	13	},			//26
	{	3,	1,	3,	9	},			//27
	{	5,	1,	2,	4,	7,	14	},			//28
	{	1,	1	},			//29
	{	7,	1,	2,	3,	5,	6,	10,	15	},			//30
	{	1,	1	},			//31
	{	5,	1,	2,	4,	8,	16	},			//32
	{	3,	1,	3,	11	},			//33
	{	3,	1,	2,	17	},			//34
	{	3,	1,	5,	7	},			//35
	{	8,	1,	2,	3,	4,	6,	9,	12,	18	},			//36
	{	1,	1	},			//37
	{	3,	1,	2,	19	},			//38
	{	3,	1,	3,	13	},			//39
	{	7,	1,	2,	4,	5,	8,	10,	20	},			//40
	{	1,	1	},			//41
	{	7,	1,	2,	3,	6,	7,	14,	21	},			//42
	{	1,	1	},			//43
	{	5,	1,	2,	4,	11,	22	},			//44
	{	5,	1,	3,	5,	9,	15	},			//45
	{	3,	1,	2,	23	},			//46
	{	1,	1	},			//47
	{	9,	1,	2,	3,	4,	6,	8,	12,	16,	24	},			//48
	{	2,	1,	7	},			//49
	{	5,	1,	2,	5,	10,	25	},			//50
	{	3,	1,	3,	17	},			//51
	{	5,	1,	2,	4,	13,	26	},			//52
	{	1,	1	},			//53
	{	7,	1,	2,	3,	6,	9,	18,	27	},			//54
	{	3,	1,	5,	11	},			//55
	{	7,	1,	2,	4,	7,	8,	14,	28	},			//56
	{	3,	1,	3,	19	},			//57
	{	3,	1,	2,	29	},			//58
	{	1,	1	},			//59
	{	11,	1,	2,	3,	4,	5,	6,	10,	12,	15,	20,	30	},			//60
	{	1,	1	},			//61
	{	3,	1,	2,	31	},			//62
	{	5,	1,	3,	7,	9,	21	},			//63
	{	6,	1,	2,	4,	8,	16,	32	},			//64
	{	3,	1,	5,	13	},			//65
	{	7,	1,	2,	3,	6,	11,	22,	33	},			//66
	{	1,	1	},			//67
	{	5,	1,	2,	4,	17,	34	},			//68
	{	3,	1,	3,	23	},			//69
	{	7,	1,	2,	5,	7,	10,	14,	35	},			//70
	{	1,	1	},			//71
	{	11,	1,	2,	3,	4,	6,	8,	9,	12,	18,	24,	36	},			//72
	{	1,	1	},			//73
	{	3,	1,	2,	37	},			//74
	{	5,	1,	3,	5,	15,	25	},			//75
	{	5,	1,	2,	4,	19,	38	},			//76
	{	3,	1,	7,	11	},			//77
	{	7,	1,	2,	3,	6,	13,	26,	39	},			//78
	{	1,	1	},			//79
	{	9,	1,	2,	4,	5,	8,	10,	16,	20,	40	},			//80
	{	4,	1,	3,	9,	27	},			//81
	{	3,	1,	2,	41	},			//82
	{	1,	1	},			//83
	{	11,	1,	2,	3,	4,	6,	7,	12,	14,	21,	28,	42	},			//84
	{	3,	1,	5,	17	},			//85
	{	3,	1,	2,	43	},			//86
	{	3,	1,	3,	29	},			//87
	{	7,	1,	2,	4,	8,	11,	22,	44	},			//88
	{	1,	1	},			//89
	{	11,	1,	2,	3,	5,	6,	9,	10,	15,	18,	30,	45	},			//90
	{	3,	1,	7,	13	},			//91
	{	5,	1,	2,	4,	23,	46	},			//92
	{	3,	1,	3,	31	},			//93
	{	3,	1,	2,	47	},			//94
	{	3,	1,	5,	19	},			//95
	{	11,	1,	2,	3,	4,	6,	8,	12,	16,	24,	32,	48	},			//96
	{	1,	1	},			//97
	{	5,	1,	2,	7,	14,	49	},			//98
	{	5,	1,	3,	9,	11,	33	},			//99
	{	8,	1,	2,	4,	5,	10,	20,	25,	50	}			//100
};

bool FirstNCharsAreEqual(const char *pszStr1, const char *pszStr2, int nSize) {
	for (int nLoop = 0; nLoop < nSize; nLoop++)
		if (pszStr1[nLoop] != pszStr2[nLoop])
			return false;

	return true;
}

bool IsRepetition(const char *pszStr, int nChunkSize, int nNoChunks) {
	for (int nLoop = 0; nLoop < nChunkSize; nLoop++) {
		for (int nLoopChunk = 1; nLoopChunk < nNoChunks; nLoopChunk++) {
			if (pszStr[nLoop] != pszStr[nLoop + nLoopChunk * nChunkSize])
				return false;
		}
	}

	return true;
}


const int MAX_TEXT_SIZE = 102;
char szLine[MAX_TEXT_SIZE];

/*
struct {
	char nMinSize;
	char nParent;
} oArr2HelperMatrix[MAX_TEXT_SIZE][MAX_TEXT_SIZE];

#define MIN_SIZE(i, j)			oArr2HelperMatrix[i][j].nMinSize	
#define PARENT(i, j)			oArr2HelperMatrix[i][j].nParent	
*/


char oArr2HelperMatrix[MAX_TEXT_SIZE][MAX_TEXT_SIZE];

#define MIN_SIZE(i, j)			oArr2HelperMatrix[i][j]	
#define PARENT(i, j)			oArr2HelperMatrix[j][i]	



std::string printSol(int nLo, int nHi) {
	if (MIN_SIZE(nLo, nHi) == nHi - nLo + 1 || nLo == nHi) {
		std::string oS(szLine + nLo, szLine + nHi  + 1);
		return oS;
	} else if (PARENT(nLo, nHi) < 0) {
		// std::string oS(szLine + nLo, szLine + nLo - oArr2HelperMatrix[nLo][nHi].nParent);
		std::string oS(printSol(nLo, nLo - PARENT(nLo, nHi) - 1));
		std::string oN = std::to_string((long long)(nHi - nLo + 1) / -PARENT(nLo, nHi));
		return oN + "(" + oS + ")";
	} else {
		std::string oS1 = printSol(nLo, PARENT(nLo, nHi));
		// std::string oS2 = printSol(PARENT(nLo, nHi) + 1, nHi);
		oS1.append(printSol(PARENT(nLo, nHi) + 1, nHi));
		return oS1;
	}
}

/*
#include <vector>
#include <iostream>
using namespace std;
*/

int main() {
	gets(szLine);
	int nLineLen = strlen(szLine);


	for (int nSize = 1; nSize <= 4; nSize++) {
		const int nLimit = nLineLen - nSize + 1;
		for (int nLoop = 0; nLoop < nLimit; nLoop++) {
			PARENT(nLoop, nLoop + nSize - 1) = -nSize;
			MIN_SIZE(nLoop, nLoop + nSize - 1) = nSize;
		}
	}

	for (int nSize = 5; nSize <= nLineLen; nSize++) {
		int nEnd = nLineLen - nSize + 1;
		for (int nLoop = 0; nLoop < nEnd; nLoop++) {
			int nCurrentMin = nSize, nParent = -nSize;
			const int nEndCurrentChunk = nLoop + nSize - 1;
			for (int nLoopMiddle = nLoop; nLoopMiddle < nEndCurrentChunk; nLoopMiddle++) {
				const int nCurrentValue = MIN_SIZE(nLoop, nLoopMiddle) + MIN_SIZE(nLoopMiddle + 1, nEndCurrentChunk);
				if (nCurrentMin > nCurrentValue) {
					nCurrentMin = nCurrentValue;
					nParent = nLoopMiddle;
				}
			}

//			int nMaxDivisor = nSize / 2;
//			for (int nChunkSize = 1; nChunkSize <= nMaxDivisor; nChunkSize++) {
			for (int nDivisorIndex = 1; nDivisorIndex <= arr2nVecDiv[nSize][0]; nDivisorIndex++) {
				const int nChunkSize = arr2nVecDiv[nSize][nDivisorIndex];
				//if (!(nSize % nChunkSize)) {
				{
					const int nNoChunks = nSize / nChunkSize;
					const int nPotentialSize = MIN_SIZE(nLoop, nLoop + nChunkSize - 1) + 2 + arrnNumberSize[nNoChunks];
					if (nPotentialSize < nCurrentMin) {
						//bool bIsRep = true;
						//for (int nLoopChunk = 1; nLoopChunk < nNoChunks; nLoopChunk++) {
						//	if (!FirstNCharsAreEqual(szLine + nLoop, szLine + nLoop + nLoopChunk * nChunkSize, nChunkSize)) {
						//		bIsRep = false;
						//		break;
						//	}
						//}

						const bool bIsRep = IsRepetition(szLine + nLoop, nChunkSize, nNoChunks);

						if (bIsRep) {
							nCurrentMin = nPotentialSize;
							nParent = -nChunkSize;
						}

					}
				}
			}

			MIN_SIZE(nLoop, nEndCurrentChunk) = nCurrentMin;
			PARENT(nLoop, nEndCurrentChunk) = nParent;
		}

	}

	// std::string oSol = printSol(0, nLineLen - 1);
	puts(printSol(0, nLineLen - 1).c_str());
	// printf("%d\n", oArr2HelperMatrix[0][nLineLen - 1].nMinSize);

	return 0;
}
