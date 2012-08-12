################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Solve():
	N = 1000;
	
	for i in range(1, N):
		for j in range(i, N):
			k = N - i - j;
			
			if (k < j):
				break;
			
			if (i ** 2 + j ** 2 == k ** 2):
				print(i * k * j);	
				return;
			





print ("PROJECT EULER 009:");
Solve();