################################################################################
#   Cristian Alexandrescu                                                      #
#   2163013577ba2bc237f22b3f4d006856                                           #
#   11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385           #
#   bc9a53289baf23d369484f5343ed5d6c                                           #
################################################################################

Input = \
[
"319",
"680",
"180",
"690",
"129",
"620",
"762",
"689",
"762",
"318",
"368",
"710",
"720",
"710",
"629",
"168",
"160",
"689",
"716",
"731",
"736",
"729",
"316",
"729",
"729",
"710",
"769",
"290",
"719",
"680",
"318",
"389",
"162",
"289",
"162",
"718",
"729",
"319",
"790",
"680",
"890",
"362",
"319",
"760",
"316",
"729",
"380",
"319",
"728",
"716"
];


def Solve():
	S = set();
	g = [[] for i in range(0, 10)];
	for line in Input:
		n1 = ord(line[0]) - ord('0');
		n2 = ord(line[1]) - ord('0');
		n3 = ord(line[2]) - ord('0');
		S = S | set({n1});
		
		if n2 not in g[n3]:
			g[n3].append(n2);
		if n1 not in g[n2]:			
			g[n2].append(n1);
	
	S = set(S);

	queue, Solution = [], [];
	for i in range(0, len(g)):
		if len(g[i]) == 0 and i in S:
			queue.append(i);
			
	while len(queue):
		n = queue.pop();
		Solution.append(n);
		for i in range(0, len(g)):
			if n in g[i]:
				g[i].remove(n);
				if len(g[i]) == 0:
					queue.append(i);

	print("Solution : ", Solution);


print ("PROJECT EULER 079:");
Solve();