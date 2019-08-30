# kartikay26

from math import *
from collections import *
from itertools import *

get = lambda : int(input())
getl = lambda : [int(x) for x in input().split()]

def main():
	for i in range(get()):
		query()

def query():
	n,m = getl()
	s = 0
	mul = []
	for i in range(1,11):
		mul += [(i*m) % 10]
		s += (i * m) % 10
	b = n // m
	ans = (b//10) * s
	a = b % 10
	for i in range(a):
		ans += mul[i]
	print(ans)

if __name__ == '__main__':
	main()