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
	n = get()
	l = getl()
	l.reverse()
	min_cur = 1e9
	ans = 0
	for x in l:
		if x > min_cur:
			ans += 1
		min_cur = min(min_cur, x)
	print(ans)

if __name__ == '__main__':
	main()