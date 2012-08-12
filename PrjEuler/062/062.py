################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def Digits(n):
	ret = [];
	while n:
		ret.append(n % 10);
		n = int(n / 10);

	return ret;

def Solve():
	A = [1];
	B = [[1]];
	
	
	
	i = 2;
	
	
	while True:
		n = i ** 3;
		D = Digits(n)
		D.sort();
		
		c = 0;
		for j in range(0, len(A)):
			if D == B[j]:
				if c == 0:
					First = A[j];
				c += 1;
		
		A.append(i);
		B.append(D);
		
		if c == 4:
			print("Solution : ", First ** 3);
			break;
			
		
		print(i);
		i += 1;


	
print ("PROJECT EULER 062");
Solve();
