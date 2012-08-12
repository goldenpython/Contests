################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

import math

def FromDigitsToNumber(digits):
	n = 0;
	for i in digits:
		n = n * 10 + i;
		
	return n;

def Solve():	
	d = [0 for i in range(0, 11)];
	Digits = set([x for x in range(0, 10)]);
	
	print(Digits);
	
	Sol = 0;
	
	for I17 in range(0, 1000, 17):
		d[10], d[9], d[8] = I17 % 10, int(I17 / 10) % 10, int(I17 / 100) % 10;
		if len(set(d[8:])) < 3:
			continue;
		for I13 in Digits - set(d[8:]):
			n = I13 * 100 + d[8] * 10 + d[9];
			if n % 13 == 0:
				d[7] = I13;	
				for I11 in Digits - set(d[7:]):
					n = I11 * 100 + d[7] * 10 + d[8];
					if n % 11 == 0:
						d[6] = I11;
						for I7 in Digits - set(d[6:]):
							n = I7 * 100 + d[6] * 10 + d[7];
							if n % 7 == 0:
								d[5] = I7;
								for I5 in Digits - set(d[5:]):
									n = I5 * 100 + d[5] * 10 + d[6];
									if n % 5 == 0:
										d[4] = I5;
										for I3 in Digits - set(d[4:]):
											n = I3 * 100 + d[4] * 10 + d[5];
											if n % 3 == 0:
												d[3] = I3;
												for I2 in Digits - set(d[3:]):
													n = I2 * 100 + d[3] * 10 + d[4];
													if n % 2 == 0:
														d[2] = I2;
														d[1] = [x for x in Digits - set(d[2:])][0];
														#if d[1]:
														n = FromDigitsToNumber(d);
														print(d, n, Digits - set(d[8:]), I3);
														Sol += n;
	
	print("Solution : ", Sol);

	
print ("PROJECT EULER 043");
Solve();
