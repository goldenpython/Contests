################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import fractions

def FraqEqual(a, b, c, d):
	return a * d == c * b;

def Solve():
	Numerator, Denominator = 1, 1;
	SolList = [];

	for a in range(10, 100):
		a1, a2 = int(a / 10), a % 10;
		for b in range(a + 1, 100):
			b1, b2 = int(b / 10), b % 10;
			
			if a1:
				if a1 == b1:
					if FraqEqual(a, b, a2, b2):
						SolList.append((a2, b2));

				if a1 == b2:
					if FraqEqual(a, b, a2, b1):
						SolList.append((a2, b1));

			if a2:
				if a2 == b1:
					if FraqEqual(a, b, a1, b2):
						SolList.append((a1, b2));

				if a2 == b2:
					if FraqEqual(a, b, a1, b1):
						SolList.append((a1, b1));
						
	for frac in SolList:
		Numerator *= frac[0];
		Denominator *= frac[1];
		
		gcd = fractions.gcd(Numerator, Denominator);
		
		Numerator = int(Numerator / gcd);
		Denominator = int(Denominator / gcd);
		
	print("Solution : ", Denominator);
		


print ("PROJECT EULER 033:");
Solve();