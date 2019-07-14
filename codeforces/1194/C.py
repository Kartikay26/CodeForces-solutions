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
		if test():
			print("YES")
		else:
			print("NO")

def isSubSequence(str1,str2):
    j = 0    # Index of str1 
    i = 0    # Index of str2 
    while j<len(str1) and i<len(str2):
        if str1[j] == str2[i]:
            j = j+1
        i = i+1
    return j==len(str1) 

def test():
	s = input()
	t = input()
	p = input()
	if isSubSequence(s, t):
		c1 = Counter(s+p)
		c2 = Counter(t)
		return all(c1[x] >= c2[x] for x in c2.keys())
	return False

if __name__ == "__main__":
	main()
