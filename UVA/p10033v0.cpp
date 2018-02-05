/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10033 - Interpreter                                              */


#include <iostream>
#include <string>

using namespace std;

int main() {
	int nNoTestCases;
	string oLine;

	for (getline(cin, oLine), nNoTestCases = stoi(oLine), getline(cin, oLine); nNoTestCases--; ) {
		struct MACHINE_STATE {
			int registers[10];
			int memory[1000];
		} oMachineState = {0};

		int nMemoryLocation = 0;
		for ( ; getline(cin, oLine) && oLine.size() > 1; )
			oMachineState.memory[nMemoryLocation++] = stoi(oLine);

		nMemoryLocation = 0;
		int nExecutedInstructions = 0;
		bool bStop = false;
		while (!bStop) {
			nExecutedInstructions++;
			int nFirstInstructionDigit = oMachineState.memory[nMemoryLocation] / 100;
			int nSecondInstructionDigit = (oMachineState.memory[nMemoryLocation] % 100) / 10;
			int nThirdInstructionDigit = oMachineState.memory[nMemoryLocation] % 10;
			switch (nFirstInstructionDigit) {
				case 1:
					bStop = true;
					break;
				case 2:
					oMachineState.registers[nSecondInstructionDigit] = nThirdInstructionDigit;
					break;
				case 3:
					oMachineState.registers[nSecondInstructionDigit] += nThirdInstructionDigit;
					oMachineState.registers[nSecondInstructionDigit] %= 1000;
					break;
				case 4:
					oMachineState.registers[nSecondInstructionDigit] *= nThirdInstructionDigit;
					oMachineState.registers[nSecondInstructionDigit] %= 1000;
					break;
				case 5:
					oMachineState.registers[nSecondInstructionDigit] = oMachineState.registers[nThirdInstructionDigit];
					break;
				case 6:
					oMachineState.registers[nSecondInstructionDigit] += oMachineState.registers[nThirdInstructionDigit];
					oMachineState.registers[nSecondInstructionDigit] %= 1000;
					break;
				case 7:
					oMachineState.registers[nSecondInstructionDigit] *= oMachineState.registers[nThirdInstructionDigit];
					oMachineState.registers[nSecondInstructionDigit] %= 1000;
					break;
				case 8:
					oMachineState.registers[nSecondInstructionDigit] = oMachineState.memory[oMachineState.registers[nThirdInstructionDigit]];
					break;
				case 9:
					oMachineState.memory[oMachineState.registers[nThirdInstructionDigit]] = oMachineState.registers[nSecondInstructionDigit];
					break;
				case 0:
					if (oMachineState.registers[nThirdInstructionDigit])
						nMemoryLocation = oMachineState.registers[nSecondInstructionDigit] - 1;
					break;
			}

			nMemoryLocation++;
		}

		cout << nExecutedInstructions << endl;
		if (nNoTestCases)
			cout << endl;
	}
	
	return 0;
}