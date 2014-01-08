/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11995 - I Can Guess the Data Structure!                          */


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void Insert(T &roStruct, int nValue) {
	roStruct.push(nValue);
}

template <>
void Insert(vector<int> &roStruct, int nValue) {
	roStruct.push_back(nValue);
}

template <typename T>
int ExtractValue(T &roStruct) {
	int nValue = roStruct.top();
	roStruct.pop();
	return nValue;
}

template <>
int ExtractValue(queue<int> &roStruct) {
	int nValue = roStruct.front();
	roStruct.pop();
	return nValue;
}

template <typename T>
bool CheckSizeAndFront(T &roStruct, int nValue) {
	return !(roStruct.size() > 0 && ExtractValue(roStruct) == nValue);
}

int main() {
	int nN;

	while (cin >> nN) {
		const int nFlagQueue = 1 << 0;
		const int nFlagStack = 1 << 1;
		const int nFlagPq = 1 << 2;

		int nFlags = nFlagQueue | nFlagStack | nFlagPq;

		vector<int> oOut;
		queue<int> oQueue;
		stack<int> oStack;
		priority_queue<int> oPQLess;

		for (int nLoop = 0; nLoop < nN; nLoop++) {
			int nOp, nNumber;
			cin >> nOp >> nNumber;

			if (nOp == 1) {
				if (nFlags | nFlagQueue)
					Insert(oQueue, nNumber);
				if (nFlags | nFlagStack)
					Insert(oStack, nNumber);
				if (nFlags | nFlagPq)
					Insert(oPQLess, nNumber);
			} else {
				if (nFlags | nFlagQueue && CheckSizeAndFront(oQueue, nNumber))
					nFlags &= ~nFlagQueue;
				if (nFlags | nFlagStack && CheckSizeAndFront(oStack, nNumber))
					nFlags &= ~nFlagStack;
				if (nFlags | nFlagPq && CheckSizeAndFront(oPQLess, nNumber))
					nFlags &= ~nFlagPq;
			}
		}

		switch (nFlags) {
			case 0:
				cout << "impossible" << endl;
				break;
			case nFlagQueue:
				cout << "queue" << endl;
				break;
			case nFlagStack:
				cout << "stack" << endl;
				break;
			case nFlagPq:
				cout << "priority queue" << endl;
				break;
			default:
				cout << "not sure" << endl;
		}
	}

	return 0;
}