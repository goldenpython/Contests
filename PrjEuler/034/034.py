################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import math

def GenFactorials(factorials, n):
	factorials.append(1);
	for i in range(1, n + 1):
		factorials.append(factorials[i - 1] * i);

	
	
def Solve(n):
	fact = [];
	GenFactorials(fact, 9);
	
	Sol = 0;
	
	for n in range(3, 10 ** 6):
		m, s = n, 0;
		while m and s <= n:
			s += fact[m % 10];
			m = int(m / 10);
			
		if s == n:
			Sol += s;
			print(s);

	print("\nSolution : ", Sol);


	
print ("PROJECT EULER 034");
Solve(1000000);
