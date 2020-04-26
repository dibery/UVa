def see(num, idx, ans):
	if num[idx][1] == -1:
		ans.append(str(num[idx][0]))
	else:
		see(num, num[idx][1], ans)
		see(num, num[idx][2], ans)

while True:
	n = int(input())
	if n == 0:
		break
	num = [(int(i), -1, -1) for i in input().split()]
	begin, end, odd, even, ans = 0, len(num), None, None, []
	while n > 1:
		for i in range(begin, end):
			if num[i][0] % 2 == 0:
				if even == None:
					even = (num[i][0], i)
				else:
					num.append(((even[0] + num[i][0]) // 2, even[1], i))
					even = None
			else:
				if odd == None:
					odd = (num[i][0], i)
				else:
					num.append(((odd[0] + num[i][0]) // 2, odd[1], i))
					odd = None
		begin, end, odd, even = end, len(num), None, None
		n >>= 1
	see(num, -1, ans)
	print('Yes\n' + ' '.join(ans))
