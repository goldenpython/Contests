################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

def AllocMatrix(Rows, Columns, Fill):
	m = [];
	l = [];
	
	for i in range(0, Rows):
		m.append([]);
		for j in range(0, Columns):
			m[i].append(Fill);		
		
	return m;

def Solve():
	m = AllocMatrix(21, 21, 0);
	
	for i in range(0, 21):
		m[i][0], m[0][i] = 1, 1;
	
	for i in range(1, 21):
		for j in range(1, 21):
			m[i][j] = m[i - 1][j] + m[i][j - 1];
			
	print(m[20][20]);
	

	
print ("PROJECT EULER 015:");
Solve();
