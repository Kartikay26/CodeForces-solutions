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
	scores = [defaultdict(int) for _ in range(m)]
	for i in range(n):
		s = input()
		for j,x in enumerate(s):
			scores[j][x] += 1
	a = getl()
	ans = 0
	for j in range(m):
		ans += max(scores[j].values()) * a[j]
	print(ans)

if __name__ == "__main__":
	main()
