################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def SumOfDivisors(n):
	sum = 1;
	
	for i in range(2, n):
		if n % i == 0:
			d = int(n / i);			
			if d > i:
				sum += i + d;
			else:
				if d == i:
					sum += i;
				break;

	return sum;
	
def IsAbundant(n):
	return SumOfDivisors(n) > n;

def Solve():
	N = 28123;
	abundant = [];
	list = [False, False];
	for i in range(2, N + 1):
		list.append(False);	
		if IsAbundant(i):
			print(i);
			abundant.append(i);			
	
	for i in range(0, len(abundant)):
		for j in range(i, len(abundant)):
			n = abundant[i] + abundant[j];
			if n > N:
				break;
			list[n] = True;

	list = [i for i in range(1, N) if list[i] == False];
	#print(list);
	
	Sum = sum(list);
	print("\n\nSum : ", Sum);




print ("PROJECT EULER 023:");
Solve();