################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import math

def CheckSolution(n):
	for i in range(8, 0, -1):
		n = int(n / 100);
		if n % 10 != i:
			return False;

	return True;

def Solve():	
	From = int(math.sqrt(10203040506070809) / 10);
	To = int(math.sqrt(19293949596979899) / 10) + 1;
	
	for i in range(From, To):
		nr = i * 10 + 3;
		if CheckSolution(nr * nr):
			break;
			
		nr = i * 10 + 7;
		if CheckSolution(nr * nr):
			break;

		if i % 10000 == 0:
			print((i - From) / (To - From) * 100, "%");

	print("Solution : ", nr * 10);


print ("PROJECT EULER 206:");
Solve();