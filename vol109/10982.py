for t in range(int(input())):
	man, pair = map(int, input().split())
	annoy, Class = [set() for i in range(man + 1)], [set(), set()]
	for i in range(pair):
		a, b = map(int, input().split())
		annoy[a].add(b)
		annoy[b].add(a)
	for i in range(1, man + 1):
		if len(Class[0] & annoy[i]) < len(Class[1] & annoy[i]):
			Class[0].add(i)
		else:
			Class[1].add(i)
	print('Case #%d: %d\n%s' % (t + 1, len(Class[1]), ' '.join(map(str, Class[1]))))
