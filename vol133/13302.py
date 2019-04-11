from fractions import Fraction
from math import ceil

while True:
	L, n, d = map(int, input().split())
	if L == 0:
		break
	ans = min(Fraction(ceil(d * b / L), b) for b in range(1, n + 1)) * L
	print(ans, end = '\n' if ans.denominator > 1 else '/1\n')
