def main():
	n,m = list(map(int, input().split()))
	data = []
	for i in range(n):
		data += [input()]
	solve_data(data)

def solve_data(data):
	data2 = [s.find("B") for s in data]
	x = 0
	while data2[x] == -1:
		x += 1
	y = len(data2) - 1
	while data2[y] == -1:
		y -= 1
	#print(y)
	#print(x)
	mid1 = (y+x)//2
	data3 = data[mid1]
	x = 0
	while data3[x] == "W":
		x += 1
	y = len(data3) - 1
	while data3[y] == "W":
		y -= 1
	mid2 = (y+x)//2
	print(mid1+1,mid2+1)

if __name__ == '__main__':
	main()