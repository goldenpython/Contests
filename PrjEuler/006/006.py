################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import fractions

def Solve():
	a, b = 1, 100;
	s1 = 0;
	
	for i in range(a, b + 1):
		s1 += i * i;
		
	s2 = int((a + b) * (b - a + 1) / 2);
	s2 *= s2;
	
	print(s2 - s1);


	
print ("PROJECT EULER 006:");
Solve();