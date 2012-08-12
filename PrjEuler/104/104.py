################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def GetDigits(n):
	Digits = [];
	while n > 0:
		Digits.append(n % 10);
		n = int(n / 10);	
	return Digits;
	
def Solve():	
	a, b = 0, 1;
	i = 2;

	Phi = (1 + math.sqrt(5)) / 2;

	while True:
		c = (a + b) % (10 ** 9);
		a, b = b, c;
		
		if i % 1000 == 0:
			print(i);
		
		LastDigits = GetDigits(c);
		LastDigits.sort();
		if LastDigits == [1, 2, 3, 4, 5, 6, 7, 8, 9]:
			print("Fib(", i, ") - ", "Last digits ok");
		else:
			i = i + 1;
			continue;
		
		LogFib = i * math.log(Phi, 10) - math.log(math.sqrt(5), 10);		
		d = int(pow(10, LogFib - int(LogFib - 8)));
		
		FirstDigits = GetDigits(d);
		FirstDigits.sort();
		if FirstDigits == [1, 2, 3, 4, 5, 6, 7, 8, 9]:
			print("Fib(", i, ") - ", "First digits ok");
		else:
			i = i + 1;
			continue;
			
		break;

	print("\n\n\nSolution : Fib(", i, ")",);

print ("PROJECT EULER 104:");
Solve();