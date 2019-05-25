from math import *
# from collections import defaultdict
# [int(x) for x in input().split()]
# a = [chr(x) for x in range(ord('A'), ord('Z')+1)]

def solve():
    a,b = [int(x) for x in input().split()]
    return (b+a-1)//a

print(solve())
