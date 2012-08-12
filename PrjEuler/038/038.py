################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################
	

def Digits(n):
	ret = [];
	while n:
		ret.append(n % 10);
		n = int(n / 10);
		
	return ret;

def Solve():
	Sol = [];
	D = set([1, 2, 3, 4, 5, 6, 7, 8, 9]);
	for a in range(9999, 5000, -1):
		b = a * 2;
		
		A = Digits(a);
		B = Digits(b);
		
		S = set(A) | set(B);
		
		if S == D:
			Sol.append(a * (10 ** len(B)) + b);

	print("Solution : ", Sol);	


print ("PROJECT EULER 038:");
Solve();