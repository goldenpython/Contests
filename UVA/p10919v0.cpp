/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10919 - Prerequisites?                                           */


#include <iostream>
#include <set>

using namespace std;

int main() {
	int nNoCourses;
	while ((cin >> nNoCourses), nNoCourses) {
		int nNoCategories;
		cin >> nNoCategories;
		set<int> oSetCourses;
		while (nNoCourses--) {
			int nCourseId;
			cin >> nCourseId;
			oSetCourses.insert(nCourseId);
		}
		bool bHasSol = true;
		while (nNoCategories--) {
			int nNoCoursesInCategory, nNoCoursesNeeded;
			cin >> nNoCoursesInCategory >> nNoCoursesNeeded;
			int nCoursesTakenInCategory = 0;
			while (nNoCoursesInCategory--) {
				int nCourseId;
				cin >> nCourseId;
				if (bHasSol && nCoursesTakenInCategory < nNoCoursesNeeded) {
					if (oSetCourses.find(nCourseId) != oSetCourses.end())
						nCoursesTakenInCategory++;
				}
			}

			if (nCoursesTakenInCategory < nNoCoursesNeeded)
				bHasSol = false;
		}

		cout << (bHasSol ? "yes\n" : "no\n");
	}

	return 0;
}