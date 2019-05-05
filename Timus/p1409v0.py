################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################


#    1409. Two Gangsters                                                       #
#    http://acm.timus.ru/problem.aspx?space=1&num=1409                         #

from sys import stdin

h, l = (int(x) for x in stdin.read().split())

sum = h + l
solH = sum - 1 - h
solL = sum - 1 - l

print("%d %d" %  (solH, solL))
