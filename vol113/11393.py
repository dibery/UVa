while True:
	s = int(input())
	if s == 0:
		break
	print('YES' if s % 3 < 2 and s > 2 else 'NO')
