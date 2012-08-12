################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

class BigInt:	
	def __init__(self, n, base = 10):
		self.Digits = [];
		self.Base = base;
		while n:
			self.Digits.append(n % base);
			n = int(n / base);
			
	def __mul__(self, n):
		r = 0;
		for i in range(0, len(self.Digits)):
			self.Digits[i] = self.Digits[i] * n + r;
			r = int(self.Digits[i] / self.Base);
			self.Digits[i] %= self.Base;
		
		while r:
			self.Digits.append(r % self.Base);
			r = int(r / self.Base);
			
		return self;
		
	def __str__(self):
		s = "";
		for i in self.Digits:
			s = "(" + str(i) + ")" + s;
		return s;

def SumOfDigits(n):
	s = 0;
	for i in n.Digits:
		r, c = 0, i;
		while c:
			r += c % 10;
			c = int(c / 10);
		
		s += r;
		

	return s;

	
def Solve():	
	Sol = [];
	for a in range(1, 100):
		n = BigInt(a, 100);
		for b in range(2, 100):
			Sol.append(SumOfDigits(n));
			n *= a;
				
			
				
	print("Solution : ", max(Sol));


print ("PROJECT EULER 056:");
Solve();