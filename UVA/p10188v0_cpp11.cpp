/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10188 - Automated Judge Script                                   */


#include <iostream>
#include <string>

using namespace std;

string ReadOutput(int nAnswerSize) {
	string oLine, oTotal;
	while (nAnswerSize--) {
		getline(cin, oLine);
		oTotal.append(" ");
		oTotal.append(oLine);
	}

	return oTotal;
}

int main() {

	for (int nCaseLoop = 1; ; nCaseLoop++) {
		string oLine;
		do {
			getline(cin, oLine);
		} while (oLine.size() == 0);
		int nReferenceAnswerSize = stoi(oLine);
		if (!nReferenceAnswerSize)
			break;

		string oReference = ReadOutput(nReferenceAnswerSize);

		do {
			getline(cin, oLine);
		} while (oLine.size() == 0);
		int nTeamAnswerSize = stoi(oLine);
		string oTeamAnswer = ReadOutput(nTeamAnswerSize);

		cout << "Run #" << nCaseLoop << ": ";
		if (oReference == oTeamAnswer) {
			cout << "Accepted" << endl;
			continue;
		}

		bool bIsPresentationError = true;
		size_t nReferenceIndex = -1, nTeamAnswerIndex = -1;
		do {
			const string oDigitList = "0123456789";
			nReferenceIndex = oReference.find_first_of(oDigitList, nReferenceIndex + 1);
			nTeamAnswerIndex = oTeamAnswer.find_first_of(oDigitList, nTeamAnswerIndex + 1);

			if ((nReferenceIndex == string::npos) != (nTeamAnswerIndex == string::npos)) {
				bIsPresentationError = false;
				break;
			}

			if (nReferenceIndex == string::npos)
				break;

			if (oReference[nReferenceIndex] != oTeamAnswer[nTeamAnswerIndex]) {
				bIsPresentationError = false;
				break;
			}

		} while (true);

		cout << (bIsPresentationError ? "Presentation Error" : "Wrong Answer") << endl;
	}

	return 0;
}