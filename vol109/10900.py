while True:
	n, p = map(float, input().split())
	if not n:
		break
	next = 1
	if p == 1:
		print('%.3f' % 2 ** n)
		continue
	for i in range(int(n)):
		next *= 2
		pa, pb = min(1 - p, 1 - 1 / next), max(0, 1 / next - p)
		next = (next * pa * (2 - pa) / 2 + pb) / (pa + pb)
	print('%.3f' % next)
