################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def IsPrime(n, Primes):
	lim = int(math.sqrt(n));
	
	for i in range(0, len(Primes)):			
		if n % Primes[i] == 0:
			return False;
			
		if Primes[i] > lim:
			break;

	return True;
	
def AppendPrimes(Primes, Limit):
	First = Primes[len(Primes) - 1];
	
	if First % 2 == 0:
		First += 1;
	else:
		First += 2;
		
	for i in range(First, Limit, 2):
		if IsPrime(i, Primes):
			Primes.append(i);
	
	#return Primes;	

def GenPrimes(Limit):
	Primes = [2, 3, 5, 7, 11];
	AppendPrimes(Primes, Limit);
	return Primes;
	
def Factorization(n, primes):
	dict = {};
	lim = int(math.sqrt(n));
	
	for i in range(0, len(primes)):
		if primes[i] * primes[i] > n:
			break;
			
		power = 0;
		while n % primes[i] == 0:
			n = int(n / primes[i]);
			power += 1;

		if power:
			dict[primes[i]] = power;
			
	if n != 1:
		dict[n] = 1;

	return dict;
	
def FactorizationIndices(n, primes):
	dict = {};
	lim = int(math.sqrt(n));
	
	for i in range(0, len(primes)):
		if primes[i] * primes[i] > n:
			break;
			
		power = 0;
		while n % primes[i] == 0:
			n = int(n / primes[i]);
			power += 1;

		if power:
			dict[i] = power;
			
	if n != 1:
		dict[primes.index(n)] = 1;

	return dict;	
