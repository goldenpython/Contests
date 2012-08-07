################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################
	
def Solve():
	Max = 100;
	Sol = [0 for i in range(0, Max + 1)];	
	Sol[0] = 1;
	
	for i in range(1, Max):
		SolTemp = [0 for j in range(0, Max + 1)];
		for j in range(0, Max + 1):
			if Sol[j]:
				for k in range(i, Max + 1 - j, i):
					SolTemp[j + k] += Sol[j];
					
		for j in range(0, Max + 1):
			Sol[j] += SolTemp[j];
			
		#print(i, Sol);
			
	print("Solution : ", Sol[Max]);


	
print ("PROJECT EULER 076");
Solve();
