################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import sys
sys.path.append("../bigint")
from bigint import BigInt
	
def Solve():	
	a = BigInt(3);
	b = BigInt(2);
	Sol = 0;
	for i in range(2, 1000):
		B = a + b;
		A = B + b;
		a, b = A, B;
		if len(a.Digits) > len(b.Digits):
			Sol += 1;
		#print(i, a, b);

	print("Solution : ", Sol);

print ("PROJECT EULER 057:");
Solve();