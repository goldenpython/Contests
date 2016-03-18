################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 13034 - Solve Everything :-)                                      #


import sys

f = sys.stdin

NoCases = int(f.readline())
for CaseLoop in range(1, NoCases + 1):
	Predictions = [int(num) for num in f.readline().split()]
	if 0 in Predictions:
		Answer = 'No'
	else:
		Answer = 'Yes'
	print('Set #' + str(CaseLoop) + ': ' + Answer)