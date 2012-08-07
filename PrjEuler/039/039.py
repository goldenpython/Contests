################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

import math



	
	
def Solve():	
	n = 1000;
	
	list = [];
	for i in range(0, n + 1):
		list.append(0);
	
	for a in range(1, n + 1):
		for b in range(a + 1, n + 1):
			c = a ** 2 + b ** 2;
			if c > n ** 2:
				break;
				
			c = int(math.sqrt(c));
			
			if c ** 2 != a ** 2 + b ** 2:
				continue;
				
			p = a + b + c;
			if p > n:
				break;

			list[p] = list[p] + 1;
	
	sol = [i for i in range(0, len(list)) if list[i] == max(list)];
	
	print(sol[0]);


	
print ("PROJECT EULER 039");
Solve();
