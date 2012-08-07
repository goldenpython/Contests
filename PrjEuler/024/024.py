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
	
	digits = [x for x in range(0, 10)];
	
	#print(fact);
	
	Sol = "";
	
	n = n - 1;
	while n or len(digits) > 0:
		i = len(digits);
		d = int(n / fact[i - 1]);
		n -= d * fact[i - 1];
		Sol += str(digits[d]);
		#print(i, digits[d], n, digits);		
		digits.remove(digits[d]);


	print(Sol);


	
print ("PROJECT EULER 024");
Solve(1000000);
