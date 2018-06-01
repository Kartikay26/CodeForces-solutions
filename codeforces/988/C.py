import os, sys, math

def main():
	T = int(input())
	lists = []
	for _ in range(T):
		lists.append(getlist())
	q,x,y,z,w = solve(lists)
	if q:
		print("YES")
		print(x,y)
		print(z,w)
	else:
		print("NO")

def getlist():
	ni = int(input())
	l = [int(x) for x in input().split()]
	return l

def solve(lists):
	occoured = {}
	for j,l in enumerate(lists):
		s = sum(l)
		for i,x in enumerate(l):
			if s-x not in occoured:
				occoured[s-x] = (i,j)
			else:
				i1,j1 = occoured[s-x]
				if j != j1:
					i2,j2 = i,j
					return (True,j1+1,i1+1,j2+1,i2+1)
	return (False,0,0,0,0)

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()