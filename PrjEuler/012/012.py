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
		
def Solve():
	primes = [2, 3];
	


	i = 20;
	while (True):
		n = (1 + i) * i / 2;
		
		lim = math.sqrt(n);
		GenPrimes(primes, lim);
		
		nn = n;
		
		m = 1;
		while n > 1:
			for PrimeFactor in primes:
				if n % PrimeFactor == 0:
					d = 0;
					while n % PrimeFactor == 0:
						n /= PrimeFactor;
						d += 1;
					m *= (d + 1);
					
			if PrimeFactor ** 2 > n and n > 1:
				m *= 2;
				break;
					
			
					
		if (m >= 500):
			print("Solution : ", int(nn), "\n", "No. Divisors : ", m);
			break;
		
		
		#print(nn, " ", i, " ", m);		
		i = i + 1;
		
		
		
	

	
print ("PROJECT EULER 012:");
Solve();
