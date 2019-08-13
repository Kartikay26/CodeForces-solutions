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
		print(test())

def test():
	n = get()
	a = getl()
	if all((a[i] - a[(i+1)%n] + n) % n == 1 or (a[i] - a[(i+1)%n] + n) % n == n-1 for i in range(n)):
		return "YES"
	else:
		return "NO"


if __name__ == "__main__":
	main()
