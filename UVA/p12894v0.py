################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 12894 - Perfect Flag                                              #


import sys
import math

f = sys.stdin

NoCases = int(f.readline())
for CaseLoop in range(0, NoCases):
	x0, y0, x1, y1, cx, cy, r = [float(num) for num in f.readline().split()]
	Err = 1E-10

	if abs((x1 - x0) / (y1 - y0) - 10 / 6.0) < Err and abs((x1 - x0) / r - 5) < Err and abs(cx - (x0 + (x1 - x0) * 4.5 / 10)) < Err and abs(cy - (y0 + y1) / 2.0) < Err:
		print("YES")
	else:
		print("NO")
