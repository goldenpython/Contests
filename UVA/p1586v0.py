################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 1586 - Molar mass                                                 #


import sys
import math

f = sys.stdin

def GetMass(AtomicName):
	if AtomicName == 'C':
		return 12.01
	if AtomicName == 'H':
		return 1.008
	if AtomicName == 'O':
		return 16.00
	if AtomicName == 'N':
		return 14.01
	return 0

NoCases = int(f.readline())
for CaseLoop in range(0, NoCases):
	Line = f.readline() + ' '
	CurrentMass = 0
	CurrentQuantity = 0
	CurrentAtomicName = ''
	for c in Line:
		if c.isdigit():
			CurrentQuantity = max(CurrentQuantity, 0.0) * 10 + ord(c) - ord('0')
		else:
			CurrentMass = CurrentMass + math.fabs(CurrentQuantity) * GetMass(CurrentAtomicName)
			CurrentAtomicName = c
			CurrentQuantity = -1
			
	print(format(CurrentMass, '.3f'))
			
		
