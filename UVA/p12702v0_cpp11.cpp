/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12702 - Dilation                                                 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // ONLINE_JUDGE
	 

template <typename T>
static istream& operator >> (istream &roStream, vector<T> &roVector) {
	#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		for (T &oElem : roVector) {
			roStream >> oElem;
		}
	#else
		for_each(roVector.begin(), roVector.end(), [&roStream](T &roElem) { roStream >> roElem; });
	#endif

	return roStream;
}

template <typename T>
static ostream& operator << (ostream &roStream, vector<T> &roVector) {
	#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		bool bPrintSpace = false;
		for (T &oElem : roVector) {
			if (bPrintSpace)
				roStream << " ";
			else 
				bPrintSpace = true;
			roStream << oElem;
		}
	#else
		roStream << *(roVector.begin());
		for_each(roVector.begin() + 1, roVector.end(), [&roStream](T &roElem) { roStream << " " << roElem; });
	#endif

	return roStream;
}


template <typename T>
void
ApplyStructuringElementAtPost(vector<vector<T>> &roImageOut, const vector<vector<T>> &roImage, const vector<vector<T>> &roStructuringElement, int nRow, int nColumn) {
	int nCenterRow = roStructuringElement.size() / 2;
	int nCenterColumn = roStructuringElement[0].size() / 2;

	const int nImageNoRows = roImage.size(), nImageNoColumns = roImage[0].size();
	const int nStructuringElementNoRows = roStructuringElement.size(), nStructuringNoColumns = roStructuringElement[0].size();
	for (int nLoopRow = 0; nLoopRow < nStructuringElementNoRows; nLoopRow++) {
		for (int nLoopColumn = 0; nLoopColumn < nStructuringNoColumns; nLoopColumn++) {
			const int nRowApply = nRow - nCenterRow + nLoopRow, nColumnApply = nColumn - nCenterColumn + nLoopColumn;
			if (nRowApply >= 0 && nRowApply < nImageNoRows && nColumnApply >= 0 && nColumnApply < nImageNoColumns)
				roImageOut[nRowApply][nColumnApply] |= roStructuringElement[nLoopRow][nLoopColumn];
		}
	}
}

template <typename T>
void
ApplyStructuringElement(vector<vector<T>> &roImageOut, const vector<vector<T>> &roImage, const vector<vector<T>> &roStructuringElement) {
	roImageOut = roImage;

	const int nImageNoRows = roImage.size(), nImageNoColumns = roImage[0].size();
	for (int nLoopRow = 0; nLoopRow < nImageNoRows; nLoopRow++)
		for (int nLoopColumn = 0; nLoopColumn < nImageNoColumns; nLoopColumn++)
			if (roImage[nLoopRow][nLoopColumn])
				ApplyStructuringElementAtPost(roImageOut, roImage, roStructuringElement, nLoopRow, nLoopColumn);
}

int main() {
	int nNoCases;
	cin >> nNoCases;

	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		int nNoRows, nNoColumns;
		cin >> nNoRows >> nNoColumns;
		vector<vector<int>> oImage(nNoRows);
		for_each(oImage.begin(), oImage.end(), [&](vector<int> &roLine) { roLine.resize(nNoColumns); cin >> roLine; });

		int nNoRowsStructuringElement, nNoColumnsStructuringElement;
		cin >> nNoRowsStructuringElement >> nNoColumnsStructuringElement;
		vector<vector<int>> oStructuringElement(nNoRowsStructuringElement);
		for_each(oStructuringElement.begin(), oStructuringElement.end(), [&](vector<int> &roLine) { roLine.resize(nNoColumnsStructuringElement); cin >> roLine; });

		vector<vector<int>> oImageResult;
		ApplyStructuringElement(oImageResult, oImage, oStructuringElement);

		cout << "Case " << nCaseLoop << ":" <<endl;
		for_each(oImageResult.begin(), oImageResult.end(), [&](vector<int> &roLine) { cout << roLine << endl; });
	}

	return 0;
}