import sys

n, m = [int(x) for x in input().split()]

a = []

for i in range(n):
    a += [[int(x) for x in input().split()]]

path = [0 for _ in range(n)]

def solve(i, curxor):
    if i == n:
        if curxor != 0:
            print("TAK")
            print(" ".join(str(i+1) for i in path))
            sys.exit(0)
        else:
            return False
    seen = set()
    for j in range(m):
        if a[i][j] not in seen:
            seen.add(a[i][j])
            path[i] = j
            solve(i+1, curxor ^ a[i][j])

if not solve(0, 0):
    print("NIE")