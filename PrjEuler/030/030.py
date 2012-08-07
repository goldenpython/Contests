################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################
	
def Solve():	
	n = 5;
	s = 0;
	
	for i1 in range(0, 10):
		print(i1);
		
		for i2 in range(0, 10):
			for i3 in range(0, 10):
				for i4 in range(0, 10):
					for i5 in range(0, 10):
						for i6 in range(0, 10):					
							p = i1 ** 5 + i2 ** 5 + i3 ** 5 + i4 ** 5 + i5 ** 5 + i6 ** 5;
							nr = i1* 100000 + i2 * 10000 + i3 * 1000 + i4 * 100 + i5 * 10 + i6;
						
							if p == nr:
								s += nr;
		

	print(s - 1);

	
print ("PROJECT EULER 030");
Solve();
