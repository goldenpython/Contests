################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

# Dickson's method: http://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples


import math
import fractions
import sys
sys.path.append("../primes")
import primes

def Solve():
	Max = 1500000;
	
	print("Generating primes");	
	PrimeList = primes.GenPrimes(int(math.sqrt(Max / 2)) + 1);
	#PrimeList = primes.GenPrimes(Max / 2);
	print("Generating primes done");
	
	
	freq = [0 for i in range(0, Max + 1)];

	for r in range(2, Max + 1, 2):
		d = primes.Factorization(r / 2, PrimeList);
		
		lastSet = set([1])
		for key in d.keys():
			d[key] = d[key] * 2;
		if d.has_key(2):
			d[2] = d[2] + 1;
		else:
			d[2] = 1;
			
		for key in d.keys():
			limit = d[key];
			lastSet = lastSet | set([g * (key ** i) for g in lastSet for i in range(0, limit + 1)])
			#for i in range(0, limit + 1):
			#	curSet = curSet | set([g * (key ** i) for g in lastSet]);
			#lastSet = lastSet | curSet;

		rr = r * r / 2;
		for s in lastSet:
			t = rr / s;
			if s <= t:
				#x = r + s;
				#y = r + t;
				#z = r + s + t;
				
				sum = 3 * r + 2 * (s + t);
				if sum <= Max:
					freq[sum] = freq[sum] + 1;		
		
		if r % 1000 == 0:
			print(r);
			
	Sol = 0;
	for i in range(0, Max + 1):
		if freq[i] == 1:
			Sol = Sol + 1;
		
	print("Solution : ", Sol);
				


print ("PROJECT EULER 075:");
Solve();