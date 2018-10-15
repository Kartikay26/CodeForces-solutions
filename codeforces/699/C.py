n = int(input())
As = [int(x) for x in input().split()]

cost_con, cost_gym, cost_rest = 0, 0, 0

def my_min(*args):
	l = []
	for c in args:
		if c is not None:
			l += [c]
	return min(l)

for x in As:
	if x == 0:
		cost_con, cost_gym, cost_rest = ( None , None , my_min(cost_rest, cost_con, cost_gym) + 1)
	elif x == 1:
		cost_con, cost_gym, cost_rest = ( my_min(cost_rest, cost_gym) , None , my_min(cost_rest, cost_con, cost_gym) + 1)
	elif x == 2:
		cost_con, cost_gym, cost_rest = ( None , my_min(cost_rest, cost_con) , my_min(cost_rest, cost_con, cost_gym) + 1)
	elif x == 3:
		cost_con, cost_gym, cost_rest = ( my_min(cost_gym, cost_rest) , my_min(cost_con, cost_rest) , my_min(cost_rest, cost_con, cost_gym) + 1)

print(my_min(cost_rest, cost_con, cost_gym))