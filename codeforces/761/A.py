#[int(x) for x in input().split()]

def solve():
    a,b = [int(x) for x in input().split()]
    if abs(a-b) > 1 or a == b == 0:
        return "NO"
    else:
        return "YES"

print(solve())
