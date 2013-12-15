/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11858 - Frosh Week                                               */


/*   Running time: 0.468s                                                     */

#include <stdio.h>
#include <string.h>


/*************************************************************/

/*			InversionHelper	class V2.0			*/
template <class T, typename TRet>
class InversionHelper {
	public:
		InversionHelper(T *parrTArray, T *parrTAuxArray) {
			m_parrTArray = parrTArray;
			m_parrTAuxArray = parrTAuxArray;
		}

		TRet GetNoInversions(int nLo, int nHi) {
			if (nLo >= nHi)
				return 0;

			int nMid = nLo + ((nHi - nLo) >> 1);

			TRet nRet1 = GetNoInversions(nLo, nMid) + GetNoInversions(nMid + 1, nHi);

			int nIndexLo = nLo;
			int nIndexHi = nMid + 1;
			int nIndexDest = 0;
			TRet nRet2 = 0;
			while (nIndexLo <= nMid && nIndexHi <= nHi) {
				if (m_parrTArray[nIndexLo] <= m_parrTArray[nIndexHi]) {
					m_parrTAuxArray[nIndexDest++] = m_parrTArray[nIndexLo++];
				} else {
					m_parrTAuxArray[nIndexDest++] = m_parrTArray[nIndexHi++];
					nRet2 += (nMid - nIndexLo + 1);
				}
			}

			if (nIndexLo <= nMid) {
				memmove(&m_parrTArray[nHi - (nMid - nIndexLo)], &m_parrTArray[nIndexLo], (nMid - nIndexLo + 1) * sizeof(T));
				memcpy(&m_parrTArray[nLo], m_parrTAuxArray, (nHi - nLo - (nMid - nIndexLo)) * sizeof(T));
			} else { // nIndexHi <= nHi
				memcpy(&m_parrTArray[nLo], m_parrTAuxArray, (nHi - nLo - (nHi - nIndexHi)) * sizeof(T));
			}

			return nRet1 + nRet2;
		}

	private:
		T *m_parrTArray, *m_parrTAuxArray;
};


/*************************************************************/

const int MAX = 1000000 + 10;

int g_arrnArray[MAX * 2];

int main() {
	int nN;

	while (scanf("%d", &nN) == 1) {
		for (int nLoop = 0; nLoop < nN; nLoop++)
			scanf("%d", &g_arrnArray[nLoop]);

		InversionHelper<int, long long> oIV(g_arrnArray, g_arrnArray + nN);
		long long llResult = oIV.GetNoInversions(0, nN - 1);
		printf("%lld\n", llResult);
	}

	return 0;
}