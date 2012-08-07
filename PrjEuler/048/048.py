################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

def ModPower(n):
	a = n;
	for i in range(1, n):
		a = (a * n) % (10 ** 10);
		
	return a;

	
def Solve():
	s = 0;
	for i in range(1, 1001):
		s += ModPower(i);
		s %= 10 ** 10;
		
	print(s);


print ("PROJECT EULER 048:");
Solve();