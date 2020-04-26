for t in range(int(input())):
	depth, a, b = map(int, input().split())
	repeat = sum(1 << i for i in range(depth) if max(a, b) << i < 1 << depth)
	print((1 << depth) - repeat)
