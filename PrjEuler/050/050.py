################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import sys
sys.path.append("../primes")
import primes

#import ../primes/primes


def Solve():	
	Max = 1000000;
	
	print("Generating primes");	
	PrimesList = primes.GenPrimes(Max);
	print("Generating primes done");		
	
	PrimeSum = [0];
	s = 0;
	for i in range(0, len(PrimesList)):
		s += PrimesList[i];
		PrimeSum.append(s);
		if PrimesList[i] * 2 > Max:
			break;
		
	PrimesList = set(PrimesList);
	Sol = -1;
	for Length in range(len(PrimeSum) - 1, 2, -1):
		print(Length);
		for i in range(0, len(PrimeSum) - Length):
			Sum = PrimeSum[i + Length] - PrimeSum[i];
			if Sum > Max:
				break;
			if Sum in PrimesList:
				Sol = Sum;
				break;
		if Sol > 0:
			break;
				
	print("Solution : ", Sol);
	


print ("PROJECT EULER 050:");
Solve();