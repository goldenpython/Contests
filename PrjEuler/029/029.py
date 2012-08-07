################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
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

def Factorization(n, primes):
	dict = {};
	
	for i in range(0, len(primes)):
		power = 0;
		while n % primes[i] == 0:
			n = int(n / primes[i]);
			power += 1;

		if power:
			dict[primes[i]] = power;

	return dict;


def Solve():
	primes = [2, 3];

	GenPrimes(primes, 100);

	Sol = [];

	for a in range(2, 100 + 1):
		FactA = Factorization(a, primes);
		for b in range(2, 100 + 1):
			FactB = {x: FactA[x] * b for x in FactA};
			
			if FactB not in Sol:
				Sol.append(FactB);
			#print(a, b, FactB);

	print("Solution : ", len(Sol));

print ("PROJECT EULER 029");
Solve();