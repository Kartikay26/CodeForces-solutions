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

seq = [4,8,15,16,23,42]

def main():
	n = get()
	l = getl()
	m = {4:0,8:0,15:0,16:0,23:0,42:0}
	discard = 0
	for x in l:
		if x not in seq:
			discard += 1
			continue
		d = seq.index(x)
		if d != 0:
			if m[seq[d-1]] != 0:
				m[x] += 1
				m[seq[d-1]] -= 1
			else:
				discard += 1
		else:
			m[x] += 1
	# print(m)
	for j,(i,k) in enumerate(m.items()):
		if i != 42:
			discard += k*(j+1)
	print(discard)

if __name__ == "__main__":
	main()
