################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def ReverseNumber(Number):
	s = 0;
	while Number:
		s = s * 10 + (Number % 10);
		Number = int(Number / 10);
		
	return s;

	
def IsPalindrome(Number):
	s = str(Number);
	i, j = 0, len(s) - 1;
	
	while (i < j):
		if (s[i] != s[j]):
			return False;
			
		i = i + 1;
		j = j - 1;
		
	return True;
	
def Solve():	
	Solution = [];

	for i in range(0, 10001):
		n = i;
		for j in range(0, 50):
			s = n + ReverseNumber(n);
			if IsPalindrome(s):
				j = -1;
				break;
			n = s;

		if j != -1:
			Solution.append(i);
			
	print("Solution : ", len(Solution));

	
print ("PROJECT EULER 055");
Solve();