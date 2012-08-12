################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import fractions

def Solve():
	Lim = 10000;
	
	Min = 1 / 3;
	Max = 1 / 2;
	
	Sol = [];
	
	for d in range(2, Lim + 1):
		for n in range(int(d / 3) - 1, int(d / 2) + 1):
			if fractions.gcd(d, n) == 1:
				f = n / d 
				if f > Min and f < Max:
					Sol.append(f);

	print("Solution : ", len(Sol));


print ("PROJECT EULER 073:");
Solve();