def calc(n, m):
	if n == 1:
		return 'Multiple' if m == 1 else 'Impossible'
	if m == 1:
		return '1'
	return 'Impossible' if (m - n) % (n - 1) != 0 or m < n else str((m - n) // (n - 1) + m + 1)

while True:
	n, m = map(int, input().split())
	if n == 0:
		break
	print('%d %d %s' % (n, m, calc(n, m)))
