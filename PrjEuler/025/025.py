################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def Add(a, b):
	c = [];
	r = 0;
	lim = min(len(a), len(b));

	for i in range(0, lim):
		r += a[i] + b[i];
		c.append(r % 10);
		r = int(r / 10);

	if lim < len(a):
		t = a;
	else:
		t = b;
		
	for i in range(lim, len(t)):
		r += t[i];
		c.append(r % 10);
		r = int(r / 10);
	
	while r:
		c.append(r % 10);
		r = int(r / 10);		
		
	#print(a, " + ", b, " = ", c);
		
	return c;

	
	
def Solve():	
	a, b = [1], [2];
	
	i = 4;
	while True:
		c = Add(a, b); 
		if len(c) == 1000:
			print(i);
			break;
			
		a = b;
		b = c;
		i = i + 1;



	
print ("PROJECT EULER 025");
Solve();
