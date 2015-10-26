/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 489 - Hangman Judge                                              */


#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string oRound;
	while (getline(cin, oRound), oRound[0] != '-') {
		string oSentence, oGuess;
		getline(cin, oSentence);
		set<char> oSetLetters(oSentence.begin(), oSentence.end());
		getline(cin, oGuess);
		int nWrongGuesses = 0;
		for (string::iterator oIt = oGuess.begin(); oIt != oGuess.end() && oSetLetters.size() > 0; oIt++)
			if (oSetLetters.find(*oIt) == oSetLetters.end()) {
				nWrongGuesses++;
				if (nWrongGuesses >= 7)
					break;
			} else {
				oSetLetters.erase(*oIt);
			}

		cout << "Round " << oRound << endl;
		if (nWrongGuesses >= 7)
			cout << "You lose." << endl;
		else if (oSetLetters.size() == 0)
			cout << "You win." << endl;
		else
			cout << "You chickened out." << endl;
	}

	return 0;
}