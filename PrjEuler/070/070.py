################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import math
import fractions
import sys
sys.path.append("../primes")
import primes


def Totient(n, PrimeList):
	d = primes.Factorization(n, PrimeList);
	
	Numerator, Denominator = n, 1;
	for j in d.keys():
		Numerator *= j - 1;
		Denominator *= j;
		gcd = fractions.gcd(Numerator, Denominator);
		Numerator = int(Numerator / gcd);
		Denominator = int(Denominator / gcd);

	return int(Numerator / Denominator);
	
def GetDigits(n):
	Digits = [];
	while n > 0:
		Digits.append(n % 10);
		n = int(n / 10);	
	return Digits;	

def Solve():
	Max = 10000000;
	
	print("Generating primes");	
	PrimeList = primes.GenPrimes(int(math.sqrt(Max)));
	print("Generating primes done");
	

	Sol = 0;
	MinRatio = Max * 2;
	
	for i in range(2, Max + 1):
		if i % 1000 == 0:
			print(i);

		Tot = Totient(i, PrimeList);
		
		if i / Tot < MinRatio:
			Digits1 = GetDigits(i);
			Digits2 = GetDigits(Tot);

			if len(Digits1) != len(Digits2):
				continue;

			Digits1.sort();
			Digits2.sort();

			if Digits1 == Digits2:
				Sol = i;
				MinRatio = i / Tot;

	print("Solution : ", Sol);



print ("PROJECT EULER 070:");
Solve();