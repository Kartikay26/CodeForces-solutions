# from collections import defaultdict
# [int(x) for x in input().split()]
# a = [chr(x) for x in range(ord('A'), ord('Z')+1)]

def solve():
    s = input()
    l = ""
    i = 0
    while i < len(s):
        if s[i] == ".":
            l += "0"
            i += 1
        elif s[i] == "-" and s[i+1] == ".":
            l += "1"
            i += 2
        elif s[i] == "-" and s[i+1] == "-":
            l += "2"
            i += 2
    # return int(l, 3)
    return l

print(solve())
