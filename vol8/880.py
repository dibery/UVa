import sys, math

def find(i):
	layer = math.ceil((math.sqrt(1 + 8 * i) - 1) / 2)
	back = layer * (layer + 1) // 2 - i
	return back + 1, layer - back

for i in sys.stdin:
	print('%d/%d' % find(int(i)))
