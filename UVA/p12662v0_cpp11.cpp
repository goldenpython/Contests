/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12662 - Good Teacher                                             */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool TeacherKnowsTheNameOfTheStudent(const string &roStudentName) {
	return roStudentName != "?";
}

void PrintNTimes(const string &roString, int nCount) {
	while (nCount--)
		cout << roString;
}

int main() {
	int nNoStudents;
	cin >> nNoStudents;

	std::vector<string> oVecoStudentNames;

	for (int nLoop = 0; nLoop < nNoStudents; nLoop++) {
		string oCurrentStudentName;
		cin >> oCurrentStudentName;
		oVecoStudentNames.push_back(move(oCurrentStudentName));
	}

	int nNoQueries;
	for (cin >> nNoQueries; nNoQueries--; ) {
		int nIndex;
		cin >> nIndex;
		nIndex--;

		if (TeacherKnowsTheNameOfTheStudent(oVecoStudentNames[nIndex])) {
			cout << oVecoStudentNames[nIndex] << endl;
			continue;
		}

		for (int nIndexLeft = nIndex - 1, nIndexRight = nIndex + 1; ; nIndexLeft--, nIndexRight++) {
			bool bValidIndexLeft = (nIndexLeft >= 0);
			bool bValidIndexRight = (nIndexRight < nNoStudents);

			if (bValidIndexLeft && bValidIndexRight){
				if (TeacherKnowsTheNameOfTheStudent(oVecoStudentNames[nIndexLeft]) && TeacherKnowsTheNameOfTheStudent(oVecoStudentNames[nIndexRight])) {
					cout << "middle of " << oVecoStudentNames[nIndexLeft] << " and " << oVecoStudentNames[nIndexRight] << endl;
					break;
				}
			}

			if (bValidIndexLeft && TeacherKnowsTheNameOfTheStudent(oVecoStudentNames[nIndexLeft])) {
				PrintNTimes("right of ", nIndex - nIndexLeft);
				cout << oVecoStudentNames[nIndexLeft] << endl;
				break;
			}

			if (bValidIndexRight && TeacherKnowsTheNameOfTheStudent(oVecoStudentNames[nIndexRight])) {
				PrintNTimes("left of ", nIndexRight - nIndex);
				cout << oVecoStudentNames[nIndexRight] << endl;
				break;
			}
		}
		
	}

	return 0;
}