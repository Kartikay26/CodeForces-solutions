import os, sys, math

def main():
	T = int(input())
	strs = []
	for _ in range(T):
		strs.append(input())
	strs.sort(key=lambda x:len(x))
	for i in range(T-1):
		if strs[i+1].find(strs[i]) == -1:
			print("NO")
			return 0
	print("YES")
	for x in strs:
		print(x)



def is_subs(x,y):
	return sum(l)

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()