# kartikay26

from math import *
from pprint import *
from sys import *
from collections import *
from itertools import *
from functools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
    for i in range(get()):
    	print(solve(get()))

def solve(n):
	x = -1
	b = int(1e8)
	while b >= 1:
		while maxsum(x+b) < n:
			x += b
		b //= 2
	return x+1

def maxsum(n):
	return (1+n//2) * (1+(n+1)//2)

if __name__ == "__main__":
    main()
