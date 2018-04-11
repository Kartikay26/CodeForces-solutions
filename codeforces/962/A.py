N = int(input())
a = [int(x) for x in input().split()]
total_problems = sum(a)
running_sum = 0
for n,ai in enumerate(a):
    running_sum += ai
    if running_sum>=total_problems/2:
        print(n+1)
        break