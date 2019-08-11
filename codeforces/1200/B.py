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
	for _ in range(get()):
		if test():
			print("YES")
		else:
			print("NO")

def test():
	n,m,k = getl()
	a = getl()
	for i in range(n-1):
		# print("dbg",i,m,a)
		if m >= a[i+1] - a[i] - k:
			m -= (a[i+1] - a[i] - k)
			a[i] += (a[i+1] - a[i] - k)
			if a[i] < 0:
				m += a[i]
				a[i] = 0
		else:
			return False
	return True

if __name__ == "__main__":
	main()
