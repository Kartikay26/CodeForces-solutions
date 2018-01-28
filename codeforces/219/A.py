"problem 219A on codeforces"

def main():
    k = int(input())
    s = input()
    print(reorder(s,k))

def reorder(s,k):
    "reorders s to be a k-string"
    r = ""
    for c in set(s):
        n = s.count(c)/k
        if int(n)!=n:
            return -1
        r += c*int(n)
    return r*k

if __name__=="__main__":
    main()
