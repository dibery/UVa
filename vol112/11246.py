def non_k(high, low, k):
	return high - low - high // k + low // k

for _ in range(int(input())):
	n, k = map(int, input().split())
	ans, step = 0, 1
	while n > 0:
		ans += non_k(n, n // k, k) * ((step + 1) // 2)
		n, step = n // k, step + 1
	print(ans)
