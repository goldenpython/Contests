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
	
def Perm(Step, NumDigits, N, Digits, Primes):
	if Step == NumDigits:
		if IsPrime(N, Primes):
			#print(N);
			return N;
		return -1;

	for i in reversed(sorted(Digits)):
		M = N * 10 + i;
		ret = Perm(Step + 1, NumDigits, M, Digits - set({i}), Primes);
		if ret != -1:
			#print(Digits);
			return ret;
			
	return -1;

def Solve():	
	print("Generating primes");
	Primes = GenPrimes(int(math.sqrt(999999999)));
	print("Generating primes done");	
	

	for i in range(9, 2, -1):
		Digits = set();
		for j in range(1, i + 1):
			Digits |= set({j});

		ret = Perm(0, i, 0, Digits, Primes);
		print(i, Digits);
		if ret != -1:
			print("Solution : ", ret);
			break;

print ("PROJECT EULER 041:");
Solve();