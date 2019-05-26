from math import *
# from collections import defaultdict
# [int(x) for x in input().split()]
# a = [chr(x) for x in range(ord('A'), ord('Z')+1)]

def solve():
    n,a,x,b,y = [int(x) for x in input().split()]
    while a != x and b != y:
        # print(a,b)
        a += 1
        if a == n+1:
            a = 1
        b += -1
        if b == 0:
            b = n
        if a == b:
            return "YES"
    return "NO"

print(solve())
