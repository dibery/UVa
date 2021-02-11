def lcm(num):
	result = 1
	for i in range(2, 100):
		exp = 0
		for j in range(len(num)):
			this_exp = 0
			while num[j] % i == 0:
				num[j] /= i
				this_exp += 1
			exp = max(exp, this_exp)
		result *= i ** exp
	return result

for i in range(int(input())):
	input()
	print('Case %d: %d' % (i + 1, lcm(list(map(int, input().split()))) * 35))
