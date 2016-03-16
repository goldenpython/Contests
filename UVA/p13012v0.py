################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 13012 - Identifying tea                                           #


import sys

f = sys.stdin

while True:
	try:
		Tea = int(f.readline())
		Answers = [int(num) for num in f.readline().split()]
		Sol = 0
		for num in Answers:
			if num == Tea:
				Sol = Sol + 1
		print(Sol)
	except:
		break