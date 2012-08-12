################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math
import types

class BigInt:	
	def __init__(self, n, base = 10):
		if isinstance(n, int):
			self.Digits = [];
			self.Base = base;
			while n:
				self.Digits.append(n % base);
				n = int(n / base);
		elif isinstance(n, list):
			self.Digits = n;
			self.Base = base;		

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
		
	def __add__(lhs, rhs):
		MaxLen = max(len(lhs.Digits), len(rhs.Digits));
		r = 0;
		Ret = [];
		for i in range(0, MaxLen):
			if i < len(lhs.Digits):
				r += lhs.Digits[i];
			if i < len(rhs.Digits):
				r += rhs.Digits[i];
			Ret.append(r % lhs.Base);
			r = int(r / lhs.Base);

		while r:
			Ret.append(r % lhs.Base);
			r = int(r / lhs.Base);
			
		RetNumber = BigInt(Ret, lhs.Base);
		#RetNumber = BigInt(0, 10);
		#RetNumber.Digits = Ret;
		#RetNumber.Base = lhs.Base;
		
		return RetNumber;
		
	def __str__(self):
		s = "";
		for i in self.Digits:
			s = "(" + str(i) + ")" + s;
		return s;