# kartikay26

from math import *
from collections import *
from itertools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
    n = int(input())
    w1 = 0
    w2 = 0
    for i in range(n):
    	a,b = getl()
    	if a>b:
    		w1 += 1
    	elif b>a:
    		w2 += 1
    if w1>w2:
    	print("Mishka")
    elif w2>w1:
    	print("Chris")
    else:
    	print("Friendship is magic!^^")

if __name__ == "__main__":
    main()
