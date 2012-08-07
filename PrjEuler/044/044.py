################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import math

def Pentagonal(n):
	return int(n * (3 * n - 1) / 2);

def Solve():
	P = [Pentagonal(1)];
	S = set(P);
	D, n = -1, 2;
	
	while D < 0:
		m = Pentagonal(n);
		P.append(m);
		S |= set([m]);
		
		for i in S:
			d = m - i;
			if d in S and d - i in S:
				if abs(d - i) < D or D < 1:
					D = abs(d - i);
					
			
		print(D, n);
		n = n + 1;

	print("Solution : ", D);

	
print ("PROJECT EULER 044");
Solve();
