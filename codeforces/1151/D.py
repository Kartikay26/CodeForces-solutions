n = int(input())
l = []
for i in range(n):
    a, b = [int(x) for x in input().split()]
    l += [(a, b, i)]

# print(l)

def keyf(ab):
    a, b, i = ab
    return - (a - b)

l.sort(key=keyf)

# print(l)

ans = 0

for i in range(n):
    ans += (n-1)*l[i][1] + i*(l[i][0] - l[i][1])

print(ans)