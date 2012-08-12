################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Solve():
	Number = 600851475143;
	Factor = 2; LastPrime = 0;
	while (Factor <= Number):
		while (Number % Factor == 0):
			Number /= Factor;
			LastPrime = Factor;
		Factor = Factor + 1;
		
	print (LastPrime);

	
print ("PROJECT EULER 003:");
Solve();