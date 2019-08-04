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
	n = get()
	a = getl()
	m = max(a)
	s = sum(a) - m
	if m <= s and (s+m) % 2 == 0:
		print("YES")
	else:
		print("NO")

if __name__ == "__main__":
	main()
