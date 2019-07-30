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
	n,x,y = getl()
	a = getl()
	for i in range(n):
		cl = []
		for j in range(i-x, i+y+1):
			if 0 <= j < n and j != i:
				cl.append(a[j])
		# print(cl)
		if len(cl) == 0 or min(cl) > a[i]:
			print(i+1)
			return

		
if __name__ == "__main__":
	main()
