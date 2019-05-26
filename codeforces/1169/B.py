from math import *

def solve():
    n,m = [int(x) for x in input().split()]
    k = [0]*(n)
    pairs = dict()
    for i in range(m):
        a,b = [int(x) for x in input().split()]
        k[a-1] += 1
        k[b-1] += 1
        if (a,b) in pairs:
            pairs[(a,b)] += 1
        else:
            pairs[(a,b)] = 1
    candidates = []
    for i in range(1,n+1):
        if k[i-1] >= m/2:
            candidates += [i]
    for i in candidates:
        for j in range(1,n+1):
            if i == j:
                continue
            x = k[i-1]
            y = k[j-1]
            intersect = pairs.get((i,j), 0) + pairs.get((j,i), 0)
            # print(i,j,"->",x,y,intersect)
            if x + y - intersect >= m:
                return "YES"
    return "NO"

print(solve())