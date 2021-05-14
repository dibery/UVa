import math, sys

def pos(seq):
	seq = int(seq)
	layer = int(seq ** .5)
	x, y = -layer / 2 + (seq - layer ** 2) // 2, -layer * 3 ** .5 / 2
	if seq - layer ** 2 & 1:
		x += .5
		y += .5 / 3 ** .5
	return x, y

for s in sys.stdin:
	a, b = map(pos, s.split())
	print('%.3f' % math.hypot(a[0] - b[0], a[1] - b[1]))
