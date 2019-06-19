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
	n,m = getl()
	l = getl()
	for i in range(n):
		l1 = sorted(l[:i], reverse=True)
		ti = l[i]
		s1 = sum(l1)
		# print(s1,l1,ti)
		ans = 0
		for c in l1:
			if s1 + ti > m:
				s1 -= c
				ans += 1
		print(ans, end=" ")

if __name__ == "__main__":
	main()
