################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import sys
sys.path.append("../primes")
import primes

#import ../primes/primes

def IsPrime(n, Primes):
	lim = int(math.sqrt(n));
	
	for i in range(0, len(Primes)):
		if Primes[i] > lim:
			break;
			
		if n % Primes[i] == 0:
			return False;

	return True;

def GenPrimes(Limit):
	Primes = [2, 3, 5, 7, 11];
	for i in range(13, Limit, 2):
		if IsPrime(i, Primes):
			Primes.append(i);
	
	return Primes;


def Solve():	
	PrimesList = primes.GenPrimes(10000);
	
	n, m = 10, 0;
	Solution = [0, 0, 0, 0];
	
	Number = 4;
	
	while True:
		s = primes.Factorization(n, PrimesList);
		if len(s) == Number:
			Solution[m] = n;
			m = m + 1;
			if m == Number:
				break;			
		else:
			m = 0;
			
		n = n + 1;
		
	print("Solution : ", Solution[0]);

print ("PROJECT EULER 047:");
Solve();