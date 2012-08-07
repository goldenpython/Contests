################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

def IsBouncy(n):
	s = str(n);
	Increasing, Decreasing = False, False;
	for i in range(1, len(s)):
		if s[i - 1] > s[i]:
			Decreasing = True;
		elif s[i - 1] < s[i]:
			Increasing = True;
			
	return Increasing and Decreasing;
			
	
def Solve():	
	Count = 0;
	
	i = 100;
	while Count / i < 0.99:
		i += 1;
		if IsBouncy(i):
			Count += 1;

	print("Solution : ", i);


print ("PROJECT EULER 112:");
Solve();