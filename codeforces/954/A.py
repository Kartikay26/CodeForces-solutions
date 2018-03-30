import re

def main():
    n = int(input())
    s = input()
    n = 1 # dummy value
    while n > 0:
        s,n = re.subn("(RU|UR)","D",s)
    print(len(s))

if __name__ == '__main__':
    main()
