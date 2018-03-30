def main():
    n = int(input())
    s = input()
    total_replaced = 0
    d = 1 # dummy value
    while d != 0:
        d,s = replstr(s)
        #print(d,s)
        total_replaced += d
    print(n - total_replaced)

def replstr(s):
    r = ""
    d = 0
    i = 0
    while i < len(s):
        z = s[i:i+2]
        if z=="UR" or z=="RU":
            r += "D"
            d += 1
            i += 1
        else:
            r += z[0]
        i += 1
    return d,r

if __name__ == '__main__':
    main()
