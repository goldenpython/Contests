################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def RecCycle(d):
	list = [];
	x = 10;
	
	while True:
		c = int(x / d);
		r = x % d;
		if r == 0:
			return 0;
			
		p = (c, r);
		if p in list:
			return len(list) - list.index(p);
		else:
			list.append(p);

		x = r * 10;
	
def Solve():	
	Solution = {x : RecCycle(x) for x in range(3, 1000)};
	Max = max(Solution.values());
	Solution = [x for x in Solution.keys() if Solution[x] == Max];
	print("Solution : ", min(Solution));
		

print ("PROJECT EULER 026:");
Solve();