################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import sys
sys.path.append("../primes")
import primes

#import ../primes/primes


def Solve():	
	Max = 100;
	
	print("Generating primes");	
	PrimeList = primes.GenPrimes(Max);
	PrimeSet = set(PrimeList);
	print("Generating primes done");		
	
	n = 9;
	while n:
		if n > PrimeList[len(PrimeList) - 1]:
			pos = len(PrimeList) - 1;
			Max = n * 2;
			primes.AppendPrimes(PrimeList, Max);
			PrimeSet |= set(PrimeList[pos:]);
			
		lim = 1 + int(math.sqrt(n / 2));
		IsSol = False;
		for i in range(0, lim):
			if (n - 2 * i * i) in PrimeSet:
				IsSol = True;
				break;
				
		if not IsSol:
			print("Solution : ", n);
			break;
		
		#print("\n", n, sorted(PrimeSet));
		print(n);
		n += 2;
				
	


print ("PROJECT EULER 046:");
Solve();