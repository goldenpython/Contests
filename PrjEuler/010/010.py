################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import fractions

def IsPrime(n, primes):
	for i in primes:
		if (n % i == 0):
			return False;
			
		if (i ** 2 > n):
			break;
			
	return True;

def Solve(limit):
	primes = [2, 3, 5, 7];
	
	n = 9;	
	while (n < limit):	
		if (IsPrime(n, primes)):
			primes.append(n);			
		n += 2;

	print(sum(primes));
	

	
print ("PROJECT EULER 010:");
Solve(2000000);
#Solve(20);