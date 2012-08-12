################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import sys
sys.path.append("../primes")
import primes

def Digits(n):
	ret = [];
	while n:
		ret.append(n % 10);
		n = int(n / 10);

	return ret;

def Solve():
	Limit = 10000;
	Primes = primes.GenPrimes(Limit);

	for i in range(0, len(Primes)):
		for j in range(i + 1, len(Primes)):
			List1 = Digits(Primes[i]);
			List2 = Digits(Primes[j]);
			List1.sort();
			List2.sort();
			
			if List1 == List2:
				diff = Primes[j] - Primes[i];
				n = Primes[j] + diff;
				List3 = Digits(n);
				List3.sort();
				if List3 == List1 and n in Primes:
					print(Primes[i], Primes[j], n);
					sol = Primes[i] * (10 ** 8) + Primes[j] * (10 ** 4) + n;
	print("Solution : ", sol);


print ("PROJECT EULER 049:");
Solve();