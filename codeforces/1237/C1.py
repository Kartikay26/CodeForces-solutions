# kartikay26

from math import *
from pprint import *
from sys import *
from collections import *
from itertools import *
from functools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
	all_points = []
	for i in range(get()):
		x,y,z = getl()
		all_points.append((x,y,z,i+1))
	all_points.sort()
	solve(all_points, 0)

def solve(points, dimension):
	if dimension == 2:
		for i in range(0,len(points),2):
			if i + 1 == len(points):
				break
			print(points[i][3], points[i+1][3])
		if len(points) % 2 == 1:
			return [points[-1]]
		else:
			return []
	else:
		remaining_pts = []
		pts_map = defaultdict(list)
		for pt in points:
			pts_map[pt[dimension]].append(pt)
		for d, pts in sorted(pts_map.items()):
			if len(pts) > 1:
				remaining_pts += solve(pts, dimension+1)
			else:
				remaining_pts.append(pts[0])
		for i in range(0,len(remaining_pts),2):
			if i + 1 == len(remaining_pts):
				break
			print(remaining_pts[i][3], remaining_pts[i+1][3])
		if len(remaining_pts) % 2 == 1:
			return [remaining_pts[-1]]
		else:
			return []

if __name__ == "__main__":
	main()
