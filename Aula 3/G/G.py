trash = input()
xyn = list(map(int, input().split()))
while (xyn[0] != 0):
	print(pow (xyn[0], xyn[1], xyn[2]))
	xyn = list(map(int, input().split()))
