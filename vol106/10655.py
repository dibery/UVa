def mul(a, b):
	ans = [[0, 0], [0, 0]]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				ans[i][j] += a[i][k] * b[k][j]
	return ans

def sol(s, p, n):
	m, i = [[s, -p], [1, 0]], [[1, 0], [0, 1]]
	while n:
		if n & 1:
			i = mul(i, m)
		m = mul(m, m)
		n >>= 1
	return i[1][0] * s + i[1][1] * 2

try:
	while True:
		print(sol(*map(int, input().split())))
except:
	pass
