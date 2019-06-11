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
	grid = []
	for i in range(n):
		grid += [input()]

	sum_i = [0]*n
	for i in range(n):
		for j in range(m):
			if grid[i][j] == '*':
				sum_i[i] += 1
	sum_j = [0]*m
	for i in range(n):
		for j in range(m):
			if grid[i][j] == '*':
				sum_j[j] += 1
	c1, r1 = (check(sum_i))
	c2, r2 = (check(sum_j))
	if c1 and c2 and grid[r1][r2] == '*':
		print ("YES")
	else:
		print ("NO")

def check(sum_i):
	i = 0
	happen_1 = False
	happen_2 = False
	happen_3 = False
	r = -1
	while i<len(sum_i) and sum_i[i] == 0:
		i += 1
	while i<len(sum_i) and sum_i[i] == 1:
		happen_1 = True
		i += 1
	while i<len(sum_i) and sum_i[i] > 1:
		if happen_2:
			return (False,0)
		happen_2 = True
		r = i
		i += 1
	while i<len(sum_i) and sum_i[i] == 1:
		happen_3 = True
		i += 1
	while i<len(sum_i) and sum_i[i] == 0:
		i += 1
	if i != len(sum_i):
		return (False,0)
	return (happen_1 and happen_2 and happen_3, r)

	# for i in range(1,n-1):
	# 	for j in range(1,m-1):
	# 		if check(grid,i,j):
	# 			print("YES")
	# 			return
	# print("NO")

# def check(grid,i,j):
# 	return	(grid[i-1][j-1] == '.' and grid[i-1][j+0] == '*' and  grid[i-1][j+1] == '.' and
# 	grid[i+0][j-1] == '*' and grid[i+0][j+0] == '*' and  grid[i+0][j+1] == '*' and
# 	grid[i+1][j-1] == '.' and grid[i+1][j+0] == '*' and  grid[i+1][j+1] == '.')


if __name__ == "__main__":
	main()
