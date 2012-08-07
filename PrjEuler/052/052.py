################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################
	
def Solve():
	
	for i in range(1, 10 ** 10):
		n1 = i;
		S1 = list(str(n1));
		S1.sort();
		
		n2 = i * 2;
		S2 = list(str(n2));
		S2.sort();		
		if S1 != S2:
			continue;
			
		n3 = i * 3;
		S3 = list(str(n3));
		S3.sort();		
		if S1 != S3:
			continue;
			
		n4 = i * 4;
		S4 = list(str(n4));
		S4.sort();		
		if S1 != S4:
			continue;
			
		n5 = i * 5;
		S5 = list(str(n5));
		S5.sort();		
		if S1 != S5:
			continue;
			
		n6 = i * 6;
		S6 = list(str(n6));
		S6.sort();		
		if S1 != S6:
			continue;						
		
		print("Solution : ", i);
		return;
		
	

print ("PROJECT EULER 052:");
Solve();