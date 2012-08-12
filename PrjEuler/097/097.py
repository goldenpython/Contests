################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def PowerMod(base, exp, mod):
	if exp == 1:
		return 2;
		
	if exp % 2:
		return 2 * PowerMod(base, exp - 1, mod);
	else:
		r = PowerMod(base, int(exp / 2), mod);
		return (r * r) % mod;

def Solve():	
	n = PowerMod(2, 7830457, 10 ** 10);
	n = (n * 28433 + 1) % (10 ** 10)

	print("Solution : ", n);


print ("PROJECT EULER 097:");
Solve();