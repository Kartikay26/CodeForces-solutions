# from collections import defaultdict
# [int(x) for x in input().split()]

def solve():
    n,k = [int(x) for x in input().split()]
    s = input()
    a = [chr(x) for x in range(ord('A'), ord('Z')+1)]
    return min(s.count(a[i]) for i in range(k)) * k

print(solve())
