################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

def Solve():
	Lim = 200;
	Coins = [1, 2, 5, 10, 20, 50, 100, 200];


	Sol = [0 for i in range(0, Lim + 1)];
	Sol[0] = 1;

	for coin in Coins:
		SolTemp = [0 for i in range(0, Lim + 1)];		
		#SolTemp[0] = 1;
		
		for i in range(0, Lim - coin + 1):
			for k in range(coin, Lim - i + 1, coin):
				if Sol[i] != 0:
					SolTemp[i + k] += Sol[i];
					
		for i in range(0, Lim + 1):
			Sol[i] += SolTemp[i];
		Sol += SolTemp;

	print("Solution : ", Sol[Lim]);


print ("PROJECT EULER 031");
Solve();
