################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def GetNoProperDivs(n):
	s = 1;
	lim = int(math.sqrt(n));
	
	for j in range(2, lim + 1):
		if n % j == 0:
			d = int(n / j);
			if j < d:
				s += j + d;
			else:
				if j == d:
					s += j;
				
	return s;
	
	
def Solve():	
	s = 0;
	
	for i in range(2, 10000):
		a = GetNoProperDivs(i);
		b = GetNoProperDivs(a);
		
		if i == b and a < 10000 and a != i:
			#print(i);
			s += i + b;
		
	print(int(s / 2));



	
print ("PROJECT EULER 021");
Solve();
