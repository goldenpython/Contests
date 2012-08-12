################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Solve():	
	Max = 10000000;
	MaxS = 81 * 9;
	S1 = set([1]);
	S89 = set([89]);
	C89 = 0;
	
	n = 1;
	
	for i in range(1, Max):
		if i % 100000 == 0:
			print(i);

		m = i;
		S = set();
		while m not in S89 and m not in S1:
			if m <= MaxS:
				S |= set([m]);			
			s = 0;
			while m:
				d = m % 10;
				s += d * d;
				m = int(m / 10);
			m = s;
				
				
		if m in S89:
			S89 |= S;
			C89 += 1;
		else:
			S1 |= S;		
			
			
	#print(sorted(S1));
	#print(sorted(S89));	
	print("Solution : ", C89);


print ("PROJECT EULER 092:");
Solve();