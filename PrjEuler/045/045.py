################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def QuadraticEquation(a, b, c):
	delta = b ** 2 - 4 * a * c;
	return [(-b - math.sqrt(delta)) / 2 / a, (-b + math.sqrt(delta)) / 2 / a];

def Positive(list):
	return [x for x in list if x > 0];
	
def Decimal(list):
	return [x for x in list if int(x) == x];

def Solve():
	n = 0;
	Sol = [];
	
	while len(Sol) < 3:
		n += 1;

		#if n % 100 == 0:
		#	print(n, Sol);

		h = n * (2 * n - 1);

		p = Decimal(Positive(QuadraticEquation(3, -1, -2 * h)));
		#print("p ", p, h);
		if not len(p):
			continue;

		t = Decimal(Positive(QuadraticEquation(1, 1, -2 * h)));
		#print("t ", t, h);		
		if not len(t):
			continue;
			
		Sol.append(h);

	print("Solution : ", Sol[2]);


print ("PROJECT EULER 045");
Solve();
