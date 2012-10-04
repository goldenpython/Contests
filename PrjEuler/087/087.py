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

def Solve():
	Max = 50000000
	MaxPrime = (int)(math.sqrt(Max) + 1);
	
	print("Generating primes");	
	PrimeList = primes.GenPrimes(MaxPrime);
	#PrimeSet = set(PrimeList);
	print("Generating primes done");
	
	Pow2 = [];
	Pow3 = [];
	Pow4 = [];
	
	for i in range(0, len(PrimeList)):
		value = PrimeList[i];
		pow2 = value ** 2;
		if pow2 <= Max:
			Pow2.append(pow2);
		else:
			break;
			
		pow3 = value ** 3;
		if pow3 <= Max:
			Pow3.append(pow3);
		else:
			continue;
		
		pow4 = value ** 4;
		if pow4 <= Max:
			Pow4.append(pow4);
	
	SolSet = set([])
	Sol = 0;
	for p2 in Pow2:
		for p3 in Pow3:
			for p4 in Pow4:
				val = p2 + p3 + p4
				if val <= Max:
					SolSet.add(val);
	Sol = len(SolSet);
	
	print("Solution : ", Sol);
				


print ("PROJECT EULER 087:");
Solve();

#					http://en.wikipedia.org/wiki/Totient