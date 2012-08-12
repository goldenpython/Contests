################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Solve():
	Largest	= 0;
	
	for i in range(999, 100, -1):
		if (i * 999 < Largest):
			break;
			
		for j in range(999, 100, -1):
			n = i * j;
			if (IsPalindrome(n) and Largest < n):
				Largest = n;
				
	print(Largest);
	
def IsPalindrome(Number):
	s = str(Number);
	i, j = 0, len(s) - 1;
	
	while (i < j):
		if (s[i] != s[j]):
			return False;
			
		i = i + 1;
		j = j - 1;
		
	return True;


print ("PROJECT EULER 004:");
Solve();