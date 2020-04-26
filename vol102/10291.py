first = True
while True:
	t = int(input())
	if t == 0:
		break
	leg = [int(input()) for i in range(t)]
	for i in sorted(set(leg), reverse=True):
		pos = [p for p in range(len(leg)) if leg[p] >= i]
		if len(pos) > 2 and all(pos[i] - pos[i - 1] + (0 if i > 0 else t) < t / 2 for i in range(len(pos))):
			if not first:
				print()
			print(sum(max(0, l - i) for l in leg))
			break
	first = False
