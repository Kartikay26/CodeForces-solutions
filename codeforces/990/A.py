import os, sys, math

def main():
	n,m,A,B = [int(x) for x in input().split()]
	a = n/m
	a_frac = a - math.floor(a)
	if a_frac <= A/(A+B):
		# easier to demolish than to build
		print((n%m)*B)
	else:
		# easier to build than demolish
		print((m-n%m)*A)


def debug(*args):
	if 'DEBUG' in os.environ:
		print(*args)

if __name__ == '__main__':
	main()