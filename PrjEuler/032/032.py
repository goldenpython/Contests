################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def DigitList(n):
	l = [];
	while n:
		l.append(n % 10);
		n = int(n / 10);
		
	return l;
	
def Solve():
	Solution = set();
	
	for a in range(1, 99999):
		D1 = DigitList(a);
		for b in range(a + 1, 99999):
			D2 = DigitList(b);
			p = a * b;
			D3 = DigitList(p);
			
			if len(D1) + len(D2) + len(D3) > 9:
				break;
				
			D = D1 + D2 + D3;
			D.sort();
			if D == [1, 2, 3, 4, 5, 6, 7, 8, 9]:
				Solution |= {p};
	
	#print(Solution);
	print("Solution : ", sum(Solution));

print ("PROJECT EULER 032:");
Solve();