import os, sys, math

def main():
	n,k = [int(x) for x in input().split()]
	l = [int(x) for x in input().split()]
	occoured = set()
	ans = []
	for i in range(n):
		if l[i] not in occoured:
			occoured.add(l[i])
			ans.append(i+1)
			if len(ans)==k:
				break
	else:
		print("NO")
		return
	print("YES")
	print(" ".join(str(x) for x in ans))

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()