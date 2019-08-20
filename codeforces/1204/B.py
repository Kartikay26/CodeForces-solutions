# kartikay26

from math import *
from collections import *
from itertools import *
from functools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
	n,l,r = getl()
	a1 = 2**l - 1 + (n - l) * 1
	a2 = 2**r - 1 + (n - r) * 2**(r-1)
	print(a1,a2)

if __name__ == "__main__":
	main()
