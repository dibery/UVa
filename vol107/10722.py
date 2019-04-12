ans = {}
for b in range(4, 129):
	ans[b, 0] = 1
	for n in range(1, 101):
		ans[b, n] = ans[b, n - 1] * b - ans[b, max(n - 2, 0)]

while True:
	b, n = map(int, input().split())
	if b == 0:
		break
	print(ans[b, n])
