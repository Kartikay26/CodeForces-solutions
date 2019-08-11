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

a = [0]*10

def main():
	n = get()
	instr = input()
	for i in instr:
		if i == 'L':
			L()
		elif i == 'R':
			R()
		else:
			a[int(i)] -= 1
	print("".join(str(x) for x in a))

def L():
	for i in range(10):
		if a[i] == 0:
			a[i] = 1
			return
def R():
	for j in range(10):
		i = 10 - j - 1
		if a[i] == 0:
			a[i] = 1
			return

if __name__ == "__main__":
	main()
