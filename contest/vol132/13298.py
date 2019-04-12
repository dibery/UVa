MOD = 1000000009

def matmul(a, b):
	output = [[0] * len(b[0]) for _ in range(len(a))]
	for i in range(len(a)):
		for j in range(len(b[0])):
			for k in range(len(b)):
				output[i][j] += a[i][k] * b[k][j]
			output[i][j] %= MOD
	return output

def calc(init, size, term):
	m = [[0] * size for _ in range(size)]
	for i in range(1, size):
		m[i][i - 1] = 1
	for i in range(size):
		m[i][-1] = 1
	for i in range(50):
		if 1 << i & term:
			init = matmul(init, m)
		m = matmul(m, m)
	return init[0][0]

while True:
	k, n = map(int, input().split())
	if k == 0:
		break
	fib = [1] + [2 ** i % MOD for i in range(k)]
	print(calc([fib], k, n))
