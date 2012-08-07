################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
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
	

	

def Solve():	
	Primes = GenPrimes(1000000);
	Primes = set(Primes);
	
	Solution = [];
	
	for i in Primes:
		if i < 9:
			continue;
			
		s = str(i);
		Valid = True;		
		for j in range(1, len(s)):
			n = int(s[j:]);
			if n not in Primes:
				Valid = False;
				break;
				
			n = int(s[0:j]);
			if n not in Primes:
				Valid = False;
				break;	

		if Valid:
			Solution.append(i);
			if len(Solution) == 11:
				break;

	print(Solution);
	print("Solution : ", sum(Solution));	


print ("PROJECT EULER 037:");
Solve();