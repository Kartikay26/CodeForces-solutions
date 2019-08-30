# kartikay26

from math import *
from collections import *
from itertools import *

get = lambda : int(input())
getl = lambda : [int(x) for x in input().split()]

def main():
	n = get()
	l = getl()
	o = 0
	e = 0
	for x in l:
		if x%2 == 1:
			o += 1
		else:
			e += 1
	print(min(o,e))


if __name__ == '__main__':
	main()