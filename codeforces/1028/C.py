def main():
	n = int(input())
	data = []
	for i in range(n):
		a,b,c,d = list(map(int, input().split()))
		data += [(a,b,c,d)]
	solve_data(data)

def intersect(tup1, tup2):
	a,b,c,d = tup1
	x,y,z,w = tup2
	return (max(a,x),max(b,y),min(c,z),min(d,w))

def solve_data(data):
	prefix = [data[0]]
	for i in range(1,len(data)):
		tup = data[i]
		prefix += [intersect(tup, prefix[-1])]
	suffix = [data[len(data)-1]]
	for i in range(1,len(data)):
		tup = data[len(data)-1-i]
		suffix += [intersect(tup, suffix[-1])]
	# print(prefix)
	# print(suffix)
	intr1 = prefix[-2]
	intr2 = suffix[-2]
	prefix = prefix[:-2]
	suffix = suffix[:-2]
	suffix.reverse()
	for pr,su in zip(prefix, suffix):
		intr = intersect(pr,su)
		a,b,c,d = intr
		if c>=a and d>=b:
			print(a,b)
			return 0
	a,b,c,d = intr1
	if c>=a and d>=b:
		print(a,b)
		return 0
	a,b,c,d = intr2
	if c>=a and d>=b:
		print(a,b)
		return 0

if __name__ == '__main__':
	main()