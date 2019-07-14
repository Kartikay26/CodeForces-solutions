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
	for i in range(int(input())):
		test()

def getgrid():
	n,m = getl()
	grid = []
	for _ in range(n):
		grid += [list(input())]
	return (grid,n,m)

def test():
	grid,n,m = getgrid()
	grid_xs = [grid[i].count('*') for i in range(n)]
	grid_ys = [0] * m
	for i in range(n):
		for j in range(m):
			grid_ys[j] += (grid[i][j] == '*')
	# print(grid_xs, grid_ys)
	z = 0
	for i in range(n):
		for j in range(m):
			k = grid_xs[i] + grid_ys[j] + (grid[i][j] == '.')
			z = max(k, z)
	print(n+m - z)

if __name__ == "__main__":
	main()
