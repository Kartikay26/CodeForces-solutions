n = int(raw_input())

i = 0

for c in range(1,n+1):
    for b in range(1,c+1):
        if c-b < c^b < b:
            i += 1

print i
