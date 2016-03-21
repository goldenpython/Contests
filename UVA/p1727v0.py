################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################

#    Problem 1727 - Counting Weekend Days                                      #


import sys
import math
import datetime

f = sys.stdin

NoCases = int(f.readline())

Months = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
Days = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]

for CaseLoop in range(0, NoCases):
	MTH, DAY = f.readline().split()
	Year = 2016
	MonthIndex = Months.index(MTH) + 1
	DayIndex = Days.index(DAY)
	while True:
		d = datetime.datetime(Year, MonthIndex, 1)
		if d.weekday() == DayIndex and Year % 4 != 0:
			break
		Year = Year + 1
		
	# print (Year)
	
	Sol = 0
	try:
		for day in range(1, 32):
			d = datetime.datetime(Year, MonthIndex, day)
			if d.weekday() == 4 or d.weekday() == 5:
				Sol = Sol + 1
	except:
		pass
		
	print(Sol)
