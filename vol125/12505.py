from decimal import Decimal, getcontext

def fraction(n):
	ans, sqrt, frac = '', n.sqrt().quantize(Decimal(1), 'ROUND_DOWN'), Decimal(1)
	for i in range(125):
		frac /= 2
		if (sqrt + frac) ** 2 > n:
			ans += '0'
		else:
			ans += '1'
			sqrt += frac
	return ans

getcontext().prec = 250
for i in range(int(input())):
	n, s = input().split()
	print(fraction(Decimal(n)).index(s))
