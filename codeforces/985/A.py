import os, sys, math

def main():
	T = int(input())
	l = [int(x)-1 for x in input().split()]
	l.sort()
	diffs_1 = [2*i-l[i] for i in range(len(l))]
	#debug(diffs_1)
	diffs_abs_1 = [abs(x) for x in diffs_1]
	d1 = sum(diffs_abs_1)
	diffs_2 = [2*i+1-l[i] for i in range(len(l))]
	#debug(diffs_2)
	diffs_abs_2 = [abs(x) for x in diffs_2]
	d2 = sum(diffs_abs_2)
	print(min(d1,d2))

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()