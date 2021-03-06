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
	
def GenCirculars(n):
	NoDigits = len(str(n));
	list = [n];
	for i in range(1, NoDigits):
		r = n % 10;
		n = int(n / 10) + r * (10 ** (NoDigits - 1))
		list.append(n);
		
	return list;
	

def Solve():
	Primes = GenPrimes(1000000);
	
	Primes = set(Primes);
	
	Sol = 0;
	for p in Primes:
		#print(p);
		list = GenCirculars(p);
		
		Circular = True;
		for pp in list:
			if pp not in Primes:
				Circular = False;
				
		if Circular:
			print("Circular ", p);
			Sol = Sol + 1;
	
	print(Sol);




print ("PROJECT EULER 035:");
Solve();