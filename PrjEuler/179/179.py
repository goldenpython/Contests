################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import fractions
import sys
sys.path.append("../primes")
import primes


Max = 10 ** 7;

def bk(Number, NumDivs, CurrentPrimeIndex, PrimeList, List):			
	if len(List) <= NumDivs:
		for i in range(len(List), NumDivs + 1):
			List.append([]);
	if NumDivs > 3:
		List[NumDivs].append(Number);
			
	for i in range(CurrentPrimeIndex, len(PrimeList)):
		j, pow = 1, PrimeList[i];
		while True:
			N = Number * pow;
			if N > Max:
				if j == 1:
					return;
				else:
					break;

			bk(N, NumDivs * (j + 1), i + 1, PrimeList, List);
			
			j = j + 1;
			pow *= PrimeList[i];

def Solve():
	print("Generating primes");	
	#PrimeList = primes.GenPrimes(int(math.sqrt(Max)));
	PrimeList = primes.GenPrimes(int(Max / 2));
	print("Generating primes done");
	
	Sol = 0;

	Lists = [];
	bk(1, 1, 0, PrimeList, Lists);
	
	print(Lists);
	for List in Lists[4:]:
		List.sort();
		for i in range(1, len(List)):
			if List[i] == List[i - 1] + 1:
				Sol = Sol + 1;
	

	print("Solution : ", Sol + 1);

print ("PROJECT EULER 179:");
Solve();
