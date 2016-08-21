################################################################################
#    Cristian Alexandrescu                                                     #
#    2163013577ba2bc237f22b3f4d006856                                          #
#    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          #
#    bc9a53289baf23d369484f5343ed5d6c                                          #
################################################################################


import sys

A = [int(x) for x in input().split(' ')]
# A = [int(x) for x in sys.stdin.read().split()]
N = A[0]
S = A[1]

# print N, S
# N = 50
# S = 300 / 2

if S % 2 != 0:
    print("0")
else:
    S = int(S / 2)
    
    a = [1 if i < 1 else 0 for i in range(0, S + 1)]
    for i in range(1, N + 1):
        b = [0 for x in range(0, S + 1)]
        for k in range(0, S + 1):
            for j in range(0, min(9, k) + 1):
                b[k] += a[k - j]
        a = b
            
    print(a[S] ** 2)