/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10810 - Ultra-QuickSort                                          */



#include <stdio.h>
#include <string.h>

/*			InversionHelper	class V1.0			*/
template <class T, typename TRet>
class InversionHelper {
	public:
		static TRet GetNoInversions(T *parrTArray, T *parrTAuxArray, int nLo, int nHi) {
			s_parrTArray = parrTArray;
			s_parrTAuxArray = parrTAuxArray;

			return GetNoInversions(nLo, nHi);
		}

	private:
		static TRet GetNoInversions(int nLo, int nHi) {
			if (nLo >= nHi)
				return 0;

			int nMid = nLo + ((nHi - nLo) >> 1);

			TRet nRet1 = GetNoInversions(nLo, nMid) + GetNoInversions(nMid + 1, nHi);

			int nIndexLo = nLo;
			int nIndexHi = nMid + 1;
			int nIndexDest = 0;
			TRet nRet2 = 0;
			while (nIndexLo <= nMid && nIndexHi <= nHi) {
				if (s_parrTArray[nIndexLo] <= s_parrTArray[nIndexHi]) {
					s_parrTAuxArray[nIndexDest++] = s_parrTArray[nIndexLo++];
				} else {
					s_parrTAuxArray[nIndexDest++] = s_parrTArray[nIndexHi++];
					nRet2 += (nMid - nIndexLo + 1);
				}
			}

			if (nIndexLo <= nMid) {
				memmove(&s_parrTArray[nHi - (nMid - nIndexLo)], &s_parrTArray[nIndexLo], (nMid - nIndexLo + 1) * sizeof(T));
				memcpy(&s_parrTArray[nLo], s_parrTAuxArray, (nHi - nLo - (nMid - nIndexLo)) * sizeof(T));
			} else { // nIndexHi <= nHi
				memcpy(&s_parrTArray[nLo], s_parrTAuxArray, (nHi - nLo - (nHi - nIndexHi)) * sizeof(T));
		
			}

			return nRet1 + nRet2;
		}

		static T *s_parrTArray, *s_parrTAuxArray;
};

template <class T, typename TRet>
T * InversionHelper<T, TRet>::s_parrTArray;

template <class T, typename TRet>
T * InversionHelper<T, TRet>::s_parrTAuxArray;


const int MAX	=	500000 + 10;

int g_arrnNumbers[MAX];
int g_arrnNumbersAux[MAX];

int main() {
	int nN;

	while (1) {
		if (scanf("%d", &nN) != 1 || !nN)
			break;

		for (int nLoop = 0; nLoop < nN; nLoop++)
			scanf("%d", &g_arrnNumbers[nLoop]);

		long long llResult = InversionHelper<int, long long>::GetNoInversions(g_arrnNumbers, g_arrnNumbersAux, 0, nN - 1);
		printf("%lld\n", llResult);
	}

	return 0;
}

