from math import pi

N = 1000
df = {i: 1 for i in (-1, 0)}
for i in range(1, 2 * N + 1):
	df[i] = df[i - 2] * i

for i in range(int(input())):
	a, b = map(int, input().split())
	a, b = max(a, b), min(a, b)
	e = ( 1 - b ** 2 / a ** 2 ) ** .5
	print('Case %d: %f' % (i + 1, sum(e ** (2 * n) / (2 * n - 1) * (df[2 * n - 1] / df[2 * n]) ** 2 for n in range(N)) * -2 * pi * a))
