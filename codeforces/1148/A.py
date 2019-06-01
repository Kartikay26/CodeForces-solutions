from math import *
# from collections import defaultdict
# [int(x) for x in input().split()]
# a = [chr(x) for x in range(ord('A'), ord('Z')+1)]

def solve():
    # n = int(input())
    a,b,c = [int(x) for x in input().split()]
    return 2*c + min(a,b) * 2 + (0 if a == b else 1)

print(solve())
