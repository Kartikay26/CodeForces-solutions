import os, sys, math

def main():
	n,m = [int(x) for x in input().split()]
	l = []
	for i in range(n):
		l.append(list(input()))
	t = [0]*m
	for i in range(m):
		for j in range(n):
			if l[j][i] == '1':
				t[i] += 1
	criticals = [False]*n
	critical_cols = [i for (i,x) in enumerate(t) if x == 1]
	#debug(critical_cols)
	for i in critical_cols:
		for j in range(n):
			if l[j][i] == '1':
				criticals[j] = True
				break
	#debug(criticals)
	if all(criticals):
		print("NO")
	else:
		print("YES")

def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()