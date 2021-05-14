for i in range(int(input())):
	s = input()
	ans = [-1] * len(s)
	for i in range(1, len(s) + 1):
		if i < 11 and int(s[-i:]) < 1 << 31:
			ans[-i] = int(s[-i:])
		else:
			for j in range(1, min(i, 11)):
				if int(s[-i:-i + j]) < 1 << 31:
					ans[-i] = max(ans[-i], int(s[-i:-i + j]) + ans[-i + j])
	print(ans[0])
