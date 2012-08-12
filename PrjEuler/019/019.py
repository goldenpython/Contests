################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

def GetNoDays(month, year):
	months = [31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
	
	if months[month] == -1:
		if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
			return 29;
		else:
			return 28;
	else:
		return months[month];
	
def Solve():
	m, y = 0, 1900;
	c = 0;
	sol = 0;
	
	while y <= 2000:
		c += GetNoDays(m, y);
		if c % 7 == 6 and y >= 1901:
			sol = sol + 1;
			
		m = m + 1;
		if m == 12:
			m = 0;
			y = y + 1;

	print(sol);

	
print ("PROJECT EULER 019");
Solve();
