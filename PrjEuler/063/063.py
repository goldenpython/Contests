################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

	
def Solve():	
	MaxB = 25;
	
	Sol = 0;
	
	for b in range(1, MaxB + 1):
		for a in range(1, 10):
			s = a ** b;
			
			if s < 10 ** b:
				if s >= 10 ** (b - 1):
					Sol += 1;
					print(a, b, s);
			else:
				break;
				
			
				
	print("Solution : ", Sol);


print ("PROJECT EULER 063:");
Solve();