/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10310 - Dog and Gopher                                           */


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
	float fX, fY;

	float DistToSq(Point &roPoint) {
		return (fX - roPoint.fX) * (fX - roPoint.fX) + (fY - roPoint.fY) * (fY - roPoint.fY);
	}

	static bool Pred(Point &roPoint) {
		return 4 * oGopherPos.DistToSq(roPoint) <= oDogPos.DistToSq(roPoint);
	}

	static Point oGopherPos, oDogPos;
};

Point Point::oGopherPos;
Point Point::oDogPos;

int main() {

	for (int nNoHoles; cin >> nNoHoles; ) {
		vector<Point> oHoles;
		float fX, fY;

		cin >> Point::oGopherPos.fX >> Point::oGopherPos.fY;
		cin >> Point::oDogPos.fX >> Point::oDogPos.fY;

		for (int nLoop = 0; nLoop < nNoHoles; nLoop++) {
			cin >> fX >> fY;
			Point oPoint = {fX, fY};
			oHoles.push_back(oPoint);
		}

		vector<Point>::iterator oIt = find_if(oHoles.begin(), oHoles.end(), Point::Pred);
		if (oIt == oHoles.end())
			cout << "The gopher cannot escape.\n";
		else
			cout << "The gopher can escape through the hole at (" << std::fixed << std::setprecision(3) << oIt->fX << "," << oIt->fY << ").\n";
	}

	return 0;
}