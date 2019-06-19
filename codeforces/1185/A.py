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
	l = getl()
	d = l[-1]
	x = l[:3]
	# print(x)
	a,b,c = sorted(x)
	# print(a,b,c,d)
	print(max(0,d-(c-b)) + max(0,d-(b-a)))

if __name__ == "__main__":
	main()
