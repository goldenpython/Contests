################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Solve():
	f1, f2 = 0, 1;	
	Sum = 0;
	
	while (True):
		f3 = f1 + f2;
		print (f1, f2, f3);
		
		if (f3 > 4000000):
			break;
		
		if (f3 % 2 == 0):
			Sum += f3;
		f1, f2 = f2, f3;
		
	print (Sum);
		
	


print ("PROJECT EULER 002:");
Solve();