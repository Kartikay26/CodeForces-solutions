def main():
    #for _ in int(input()):
    testcase()

def testcase():
    n,m = [int(x) for x in input().split()]
    l = [int(x) for x in input().split()]
    print(solve(n,m,l))

def solve(n,m,l):
    counts = [0]*n
    points = 0
    for col in l:
        counts[col-1] += 1
        for x in counts:
            if x==0:
                break
        else:
            points += 1
            counts = [x-1 for x in counts]
    return points

if __name__ == "__main__":
    main()
