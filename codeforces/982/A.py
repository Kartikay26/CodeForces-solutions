import os, sys, math
import re

def main():
	T = int(input())
	#for _ in range(T):
	testcase()

def testcase():
	l = input()
	if solve(l):
		print("Yes")
	else:
		print("No")

def solve(l):
	if l=="0":
		return False
	if re.search("11",l):
		return False
	if re.search("000",l):
		return False
	if re.search("00$",l):
		return False
	if re.search("^00",l):
		return False
	return True

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()