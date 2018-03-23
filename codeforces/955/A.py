import math

def main():
    hh,mm = [int(x) for x in input().split()]
    t = hh*60+mm
    H,D,C,N = [int(x) for x in input().split()]
    if t>20*60:
        print(math.ceil(H/N)*C*0.8)
    else:
        c1 = math.ceil(H/N)*C
        dt = 20*60-t
        c2 = math.ceil((H+D*dt)/N) * C * 0.8
        print(min(c1,c2))

if __name__ == "__main__":
    main()
