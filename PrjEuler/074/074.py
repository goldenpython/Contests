################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def SumDigitsFact(n, Factorial):
	s = 0;
	while (n > 0):
		s += Factorial[n % 10];
		n = int(n / 10);
	return s;

def Solve():
	Factorials = [1];
	for i in range(1, 10):
		Factorials.append(Factorials[i - 1] * i);

	Lim = 1000000;

	Sol = [];
	SetGlobl = set();
	ChainLength = [0 for i in range(0, (Factorials[9] + 1) * 6)];
	
	ChainLength[169] = 3; ChainLength[363601] = 3; ChainLength[1454] = 3;
	ChainLength[871] = 2; ChainLength[45361] = 2;
	ChainLength[872] = 2; ChainLength[45362] = 2;

	for i in range(3, Lim):
		if i % 1000 == 0:
			print(i)

		if ChainLength[i] == 0:
			SetCur = [];
			m, c = i, 0;
			while True:
				SetCur.append(m);
				if ChainLength[m] != 0:
					break;
				mm = SumDigitsFact(m, Factorials);
				if mm == m:
					ChainLength[mm] = -1;
				m = mm;
				c = c + 1;

			for j in range(len(SetCur) - 2, -1, -1):
				ChainLength[SetCur[j]] = ChainLength[SetCur[j + 1]] + 1;
			if ChainLength[i] == 60:
				Sol.append(i);

	print(Sol);
	print("\n\n\n");
	print("Solution : ", len(Sol));


print ("PROJECT EULER 074:");
Solve();