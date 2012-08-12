################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import sys

def Collatz(n, prec):
	if n < len(prec):
		if prec[n] != 0:
			return prec[n];
		
	if n == 1:
		return 1;
		
	if n % 2 == 0:
		m = int(n / 2);
	else:
		m = 3 * n + 1;
		
	#print(m);
	
	if n < len(prec):
		prec[n] = 1 + Collatz(m, prec);
		return prec[n];
	else:
		return 1 + Collatz(m, prec);
		
def Solve():
	s = [];
	for i in range(0, 1000000):
		s.append(0);
	s[1] = 1;

	
	sys.setrecursionlimit(100000);
	
	for i in range(1, len(s)):
		Collatz(i, s);
			
	print(s.index(max(s)));
	

	
print ("PROJECT EULER 014:");
Solve();
