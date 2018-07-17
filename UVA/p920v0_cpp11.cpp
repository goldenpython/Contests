/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 920 - Sunny Mountains                                            */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

template<typename T>
void ReadArray(std::vector<T> &roVecElementsArray) {
	int nN;
	std::cin >> nN;
	roVecElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVecElementsArray.emplace_back(oElement);
	}
}

using namespace std;

class CPoint {
	public:
		double DistanceTo(const CPoint &rcoPoint) const;
		int GetY() const;
	private:
		int m_nX, m_nY;
		friend istream& operator >> (istream &roInputStream, CPoint &roPoint);
		friend bool operator < (const CPoint &rcoPointLHS, const CPoint &rcoPointRHS);
};

double CPoint::DistanceTo(const CPoint &rcoPoint) const {
	return sqrt(static_cast<double>((rcoPoint.m_nX - this->m_nX) * (rcoPoint.m_nX - this->m_nX) + (rcoPoint.m_nY - this->m_nY) * (rcoPoint.m_nY - this->m_nY)));
}

int CPoint::GetY() const {
	return m_nY;
}

istream& operator >> (istream &roInputStream, CPoint &roPoint) {
	roInputStream >> roPoint.m_nX >> roPoint.m_nY;
	return roInputStream;
}

bool operator < (const CPoint &rcoPointLHS, const CPoint &rcoPointRHS) {
	return rcoPointLHS.m_nX > rcoPointRHS.m_nX;
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		vector<CPoint> oVecPoints;
		ReadArray(oVecPoints);
		sort(oVecPoints.begin(), oVecPoints.end());

		CPoint &rcoPrevPoint = oVecPoints[0];
		int nYMaxHeight = 0;
		double lfSol = 0.0;
		for_each(
			next(oVecPoints.cbegin()), 
			oVecPoints.cend(),
			[&nYMaxHeight, &rcoPrevPoint, &lfSol](const CPoint &rcoCurrentPoint) {
				if (rcoCurrentPoint.GetY() > nYMaxHeight) {
					lfSol += rcoCurrentPoint.DistanceTo(rcoPrevPoint) * (rcoCurrentPoint.GetY() - nYMaxHeight) / (rcoCurrentPoint.GetY() - rcoPrevPoint.GetY());
					nYMaxHeight = rcoCurrentPoint.GetY();
				}
				rcoPrevPoint = rcoCurrentPoint;
			}
		);

		cout << fixed << setprecision(2) << lfSol << endl;
	}

	return 0;
}