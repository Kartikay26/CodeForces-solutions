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
	s = input()
	n = len(s)
	ans = n // 2
	if s[1:].count('1') and n % 2 == 1:
		ans += 1
	print(ans)

if __name__ == "__main__":
	main()
