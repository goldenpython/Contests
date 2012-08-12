################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def IsPrime(n, primes):
	for i in primes:
		if (n % i == 0):
			return False;
			
		if (i ** 2 > n):
			break;
			
	return True;

def GenPrimes(primes, limit):	
	n = primes[len(primes) - 1] + 2;	
	while (n < limit):	
		if (IsPrime(n, primes)):
			primes.append(n);			
		n += 2;
		
def QuadraticFormula(n, a, b):
	return n ** 2 + n * a + b;

def PrimesChain(a, b, primes):
	n = 0;
	while True:
		f = QuadraticFormula(n, a, b);
		if f not in primes:
			return n;
		n += 1;
				
def Solve():
	primes = [2, 3];
	GenPrimes(primes, 100000);
	primes = set(primes);
	
	min = 1000;
	
	max, sol = -1, 0;
	
	print(PrimesChain(-79, 1601, primes));
	
	
	for a in range(-min, min + 1):
		for b in range(-min, min + 1):
			n = PrimesChain(a, b, primes);
			if n > max:
				max, sol = n, a * b;
				print(a, b, n, max, sol);
				break;

	print("Solution : ", sol);

		
		
		
	

	
print ("PROJECT EULER 027:");
Solve();
