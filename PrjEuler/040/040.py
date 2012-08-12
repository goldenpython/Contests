################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def GetDigit(n):
	i = 0;
	while n > (i + 1) * 9 * (10 ** i):
		n -= (i + 1) * 9 * (10 ** i);
		i += 1;
	
	i += 1;
		
	m = int((n - 1) / i);
	d = (n - 1) % i;
	m = int((10 ** (i - 1) + m) / (10 ** (i - d - 1))) % 10;
	#m = int(10 ** (i - 1) + m);
	#print(d);
	
	return m;
		

def Solve():
	Lim = 1000000;
	
	#for i in range(1, 200):
	#	print(i, GetDigit(i));
	
	print("Solution : ", GetDigit(1) * GetDigit(10) * GetDigit(100) * GetDigit(1000) * GetDigit(10000) * GetDigit(100000) * GetDigit(1000000));


print ("PROJECT EULER 040");
Solve();
