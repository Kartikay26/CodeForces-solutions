import os, sys, math

def main():
	T = int(input())
	#for _ in range(T):
	testcase()

def testcase():
	l = [int(x) for x in input().split()]
	print(solve(l))

def solve(l):
	l.sort()
	n = len(l)
	if n%2==0:
		i = n//2-1
	else:
		i = n//2
	return l[i]

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()