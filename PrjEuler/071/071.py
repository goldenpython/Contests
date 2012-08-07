################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import fractions

def Solve():
	Max = 1000000;
	
	SolN = 0;
	SolD = 1;
	
	for d in range(1, Max + 1):
#		if d % 10000 == 0:
#			print(d);
		for n in range(int(3 / 7 * d) + 1, 0, -1):
			if fractions.gcd(n, d) == 1 and n / d < 3 / 7:
				if n / d > SolN / SolD:
					SolN, SolD = n, d;
					
				break;

	print("Solution : ", SolN);
		
		

print ("PROJECT EULER 071:");
Solve();