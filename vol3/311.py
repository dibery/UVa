while True:
	pkg = list(map(int, input().split()))
	if sum(pkg) == 0:
		break
	ans = sum(pkg[-3:]) + (3 + pkg[2]) // 4
	
	pkg[0] = max(pkg[0] - 11 * pkg[4], 0)

	rm = min(5 * pkg[3], pkg[1])
	pkg[1] -= rm
	pkg[0] = max(pkg[0] - (20 * pkg[3] - 4 * rm), 0)

	pkg[2] %= 4
	
	if pkg[2]:
		left = 36 - 9 * pkg[2]
		rm = min(7 - 2 * pkg[2], pkg[1])
		pkg[1] -= rm
		left -= 4 * rm
		pkg[0] = max(pkg[0] - left, 0)
	
	ans += (8 + pkg[1]) // 9
	pkg[1] %= 9
	if pkg[1]:
		pkg[0] = max(pkg[0] - (36 - 4 * pkg[1]), 0)
	
	ans += (pkg[0] + 35) // 36
	print(ans)
