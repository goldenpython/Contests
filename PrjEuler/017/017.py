################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def NoLetters(n, dict):
	s = "" + str(n) + ":";
	
	ret = 0;
	
	a = int(n / 1000);
	if a:
		s += dict[a] + " " + dict[1000];
		ret += len(dict[a]) + len(dict[1000]);
		
	n %= 1000;
	a = int(n / 100);
	if a:
		s += dict[a] + " " + dict[100];
		ret += len(dict[a]) + len(dict[100]);
		
	n %= 100;
	if n >= 1 and n <= 19:
		if ret:
			s += " and ";
			ret += 3;
			
		s += dict[n];
		ret += len(dict[n]);
	else:
		if ret and n:
			s += " and ";
			ret += 3;
			
		if n / 10 >= 1:
			s += dict[int(n / 10) * 10]
			ret += len(dict[int(n / 10) * 10])
		
		if n % 10:
			s += " " + dict[n % 10];
			ret += len(dict[n % 10]);
		
	#print(s);
	return ret;
		
	
def Solve():
	s = {};
	s[0] = 'zero';
	s[1] = 'one';
	s[2] = 'two';
	s[3] = 'three';
	s[4] = 'four';
	s[5] = 'five';
	s[6] = 'six';
	s[7] = 'seven';
	s[8] = 'eight';
	s[9] = 'nine';
	s[10] = 'ten';
	s[11] = 'eleven';
	s[12] = 'twelve';
	s[13] = 'thirteen';
	s[14] = 'fourteen';
	s[15] = 'fifteen';
	s[16] = 'sixteen';
	s[17] = 'seventeen';
	s[18] = 'eighteen';
	s[19] = 'nineteen';
	s[20] = 'twenty';
	s[30] = 'thirty';	
	s[40] = 'forty';
	s[50] = 'fifty';
	s[60] = 'sixty';
	s[70] = 'seventy';
	s[80] = 'eighty';
	s[90] = 'ninety';
	s[100] = 'hundred';
	s[1000] = 'thousand';
	
	sum = 0;
	for i in range(1, 1000 + 1):
		sum += NoLetters(i, s);
		
	print(sum);
	


	
print ("PROJECT EULER 017:");
Solve();
