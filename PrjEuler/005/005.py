################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import fractions

def Solve():
	n = 1;
	for i in range(1, 20):
		n = n * i / fractions.gcd(n, i);
	
	print(int(n));


	
print ("PROJECT EULER 005:");
Solve();