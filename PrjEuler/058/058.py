################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import fractions
from bisect import bisect
import sys
sys.path.append("../primes")
import primes

#import ../primes/primes

def CheckPrimeList(c, Primes):
	pos = len(Primes) - 1;
	if Primes[len(Primes) - 1] < c:
		Max = int(c * 150 / 100);
		primes.AppendPrimes(Primes, Max);

def Solve():	

	Primes = primes.GenPrimes(100);
	
	c, s = 1, 1;
	i = 1;
	PrimesInDiag1, PrimesInDiag2 = 0, 0;
	
	while True:
		c = c + i * 2;
		s = s + c;
		CheckPrimeList(int(math.sqrt(c)) + 1, Primes);
		if primes.IsPrime(c, Primes):
			PrimesInDiag1 += 1;
		#print(c);
			
		
		c = c + i * 2;
		s = s + c;
		CheckPrimeList(int(math.sqrt(c)) + 1, Primes);
		if primes.IsPrime(c, Primes):
			PrimesInDiag2 += 1;		
		#print(c);			

		c = c + i * 2;
		s = s + c;
		CheckPrimeList(int(math.sqrt(c)) + 1, Primes);
		if primes.IsPrime(c, Primes):
			PrimesInDiag1 += 1;		
		#print(c);			
		
		c = c + i * 2;
		s = s + c;
		CheckPrimeList(int(math.sqrt(c)) + 1, Primes);
		if primes.IsPrime(c, Primes):
			PrimesInDiag2 += 1;
		#print(c);
		
		n = i * 2 + 1;		
		print(i, PrimesInDiag1, PrimesInDiag2, PrimesInDiag1 / n, PrimesInDiag2 / n, (PrimesInDiag1 + PrimesInDiag2) / (n * 2 - 1));
		if (PrimesInDiag1 + PrimesInDiag2) / (n * 2 - 1) < 0.1:
			break;

		i += 1;

	print("Solution : ", i * 2 + 1);

	
print ("PROJECT EULER 058");
Solve();
