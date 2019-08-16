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
	for i in range(get()):
		if test():
			print("YES")
		else:
			print("NO")

def test():
	n = get()
	a = getl()
	a.sort()
	b = []
	for i in range(2*n):
		if a[2*i] != a[2*i+1]:
			return False
		b += [a[2*i]]
	for i in range(n):
		if b[i] * b[2*n-i-1] != b[0] * b[2*n-1]:
			return False
	return True

if __name__ == "__main__":
	main()
