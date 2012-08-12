################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def IsPalindrome(s):
	i, j = 0, len(s) - 1;
	while i < j:
		if s[i] != s[j]:
			return False;
		
		i, j = i + 1, j - 1;
			
	return True;

def ToBase2(n):
	s = "";
	while n != 0:
		s = str(n % 2) + s;
		n = int(n / 2);
	
	return s;

def Solve():
	Sum = 0;
	
	for i in range(1, 1000001):
		s1 = str(i);
		if IsPalindrome(s1) == False:
			continue;
			
		s2 = ToBase2(i);
		if IsPalindrome(s2):
			print(i);
			Sum += i;
			
	print("Sum : ", Sum);

	
print ("PROJECT EULER 036");
Solve();
