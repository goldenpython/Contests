################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import fractions
import sys
sys.path.append("../primes")
import primes

#import ../primes/primes

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

def Solve():
	Max = 1000000;
	
	print("Generating primes");	
	PrimeList = primes.GenPrimes(Max);
	#PrimeSet = set(PrimeList);
	print("Generating primes done");
	

	Sol = 0;
	for i in range(2, Max + 1):
		Sol += Totient(i, PrimeList);
			

		
	print("Solution : ", Sol);
				


print ("PROJECT EULER 072:");
Solve();

#					http://en.wikipedia.org/wiki/Totient