for t in range(int(input())):
	n, k, m = map(int, input().split())
	p = [float(input()) for i in range(n)]
	ans = [p[0]]
	while len(ans) < m:
		ans.append(sum(p[i] * ans[-1] ** i for i in range(n)))
	print('Case #%d: %.7f' % (t + 1, ans[-1] ** k))
