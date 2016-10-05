/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1920. Titan Ruins: the Infinite Power of Magic                   */
/*   http://acm.timus.ru/problem.aspx?num=1920                                */

#include <stdio.h>
#include <math.h>

int DistToTarget(int nRow, int nColumn) {
	return abs(nColumn - 1) + nRow;
}

void Print(int nRow, int nColumn) {
	printf("%d %d\n", nRow + 1, nColumn + 1);
}

int Sgn(int nNumber) {
	return nNumber > 0 ? 1 : -1;
}

void StraightToTargetRow(int &rnRow, int &rnColumn) {
	while (rnRow > 0)
		Print(--rnRow, rnColumn);
}

void StraightToTargetColumn(int &rnRow, int &rnColumn) {
	while (rnColumn != 1)
		Print(rnRow, rnColumn += Sgn(1 - rnColumn));
}


int main() {
	int nN, nL;
	scanf("%d %d", &nN, &nL);

	if (nL % 2 == 1 || nL > nN * nN) {
		printf("Unsuitable device\n");
		return 0;
	}

	printf("Overwhelming power of magic\n");

	typedef enum {
		DOWN,
		LEFT, 
		RIGHT,
		UP,
		ZIGZAG_LEFT,
		ZIGZAG_UP,
		ZIGZAG_DOWN
	} DIRECTION;

	int nCurrentDistance = DistToTarget(0, 0);
	int nLengthRemaining = nL - 1;
	int nColumn = 0, nRow  = 0;
	DIRECTION eCurrentDir = DOWN;
	do {
		Print(nRow, nColumn);
		switch (eCurrentDir) {
			case DOWN:
				nRow++;
				if (nRow == nN - 1)
					eCurrentDir = RIGHT;
				break;

			case RIGHT:
				nColumn++;
				if (nColumn == nN - 1)
					eCurrentDir = UP;
				break;

			case UP:
				nRow--;

				if (nN % 2 == 1 && nRow == 1)
					eCurrentDir = ZIGZAG_UP;
				else if (nColumn == 1)
					eCurrentDir = RIGHT;
				else
					eCurrentDir = LEFT;
				// if (nColumn == nN - 1)
				//	eCurrentDir = UP;
				break;

			case LEFT:
				nColumn--;
				if (nColumn == 1)
					eCurrentDir = UP;
				break;

			case ZIGZAG_UP:
				nRow--;
				eCurrentDir = ZIGZAG_LEFT;
				break;

			case ZIGZAG_LEFT:
				nColumn--;
				if (nRow == 0)
					eCurrentDir = ZIGZAG_DOWN;
				else
					eCurrentDir = ZIGZAG_UP;
				break;

			case ZIGZAG_DOWN:
				nRow++;
				eCurrentDir = ZIGZAG_LEFT;
				break;
		};

		nCurrentDistance = DistToTarget(nRow, nColumn);
		nLengthRemaining--;
	} while (nLengthRemaining > nCurrentDistance);

	Print(nRow, nColumn);

	if (nColumn == 0 || eCurrentDir == ZIGZAG_LEFT) {
		StraightToTargetColumn(nRow, nColumn);
		StraightToTargetRow(nRow, nColumn);
	} else {
		StraightToTargetRow(nRow, nColumn);
		StraightToTargetColumn(nRow, nColumn);
	}


	return 0;
}