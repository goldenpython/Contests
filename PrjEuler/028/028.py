################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################
	
def Solve():	
	n = 1001;
	m = int((n - 1) / 2);
	
	
	c, s = 1, 1;
	
	for i in range(1, m + 1):
		c = c + i * 2; 
		s = s + c;
		
		c = c + i * 2; 
		s = s + c;

		c = c + i * 2; 
		s = s + c;
		
		c = c + i * 2; 
		s = s + c;		
		

	print(s);

	
print ("PROJECT EULER 028");
Solve();
