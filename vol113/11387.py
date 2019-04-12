def four(n):
	print('\n'.join('%d %d' % (i, j) for i in range(n, n + 4) for j in range(i + 1, n + 4)))

def six():
	print('\n'.join('%d %d' % (a[0], a[1]) for a in
		[(1, 2), (1, 3), (1, 4), (2, 3), (2, 5), (3, 6), (4, 5), (4, 6), (5, 6)]))

while True:
	n = int(input())
	if n == 0:
		break
	elif n % 2 == 1 or n < 4:
		print('Impossible')
	elif n % 4 == 0:
		print(n * 3 // 2)
		for i in range(1, n, 4):
			four(i)
	else:
		print(n * 3 // 2)
		six()
		for i in range(7, n, 4):
			four(i)
