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
		test()

def test():
	x = input()
	y = input()
	y1, y2 = 0, 0
	for i in range(len(y)):
		if y[len(y)-i-1] == '1':
			y1 = i
			break
	for i in range(y1, len(x)):
		if x[len(x)-i-1] == '1':
			y2 = i
			break
	print(y2-y1)

if __name__ == "__main__":
	main()
