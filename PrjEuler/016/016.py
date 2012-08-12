################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import decimal

def Solve():

	arr = [1];
	for i in range(1, 1001):
		x = 0;
		for j in range(0, len(arr)):
			x += arr[j] * 2;
			arr[j] = x % 10;
			x = int(x / 10);
			
		if x > 0:
			arr.append(x);
			
			
	print(sum(arr));

	
print ("PROJECT EULER 016:");
Solve();
