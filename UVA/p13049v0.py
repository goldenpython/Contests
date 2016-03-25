################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 13049 - Combination Lock                                          #


import sys

Fin = sys.stdin



NoCases = int(Fin.readline())
for CaseLoop in range(1, NoCases + 1):
	NoWheels, StateInitial, StateTarget = Fin.readline().split()
	Steps = 0
	for WheelLoop in range(0, int(NoWheels)):
		Diff = ord(StateInitial[WheelLoop]) - ord(StateTarget[WheelLoop]);
		Steps = Steps + min((10 + Diff) % 10, (10 - Diff) % 10)
	print("Case " + str(CaseLoop) + ": " + str(Steps))