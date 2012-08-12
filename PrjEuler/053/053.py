################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def Combin(n, r, Logs):
	return Logs[n] - Logs[n - r] - Logs[r];
	
def Solve():
	Lim = 100;

	Logs = [0];
	for i in range(1, Lim + 1):
		Logs.append(Logs[i - 1] + math.log(i));
		
	LimLog = math.log(1000000);

	print("Solution : ", len([(i, j) for i in range(1, Lim + 1) for j in range(1, i + 1) if Combin(i, j, Logs) >= LimLog]));
	


print ("PROJECT EULER 053:");
Solve();