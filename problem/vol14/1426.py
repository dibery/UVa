def sqrt( n ):
	l, h, m = 1, n, n // 2
	while h - l > 10:
		sq = m ** 2
		if sq == n:
			return m
		elif sq > n:
			l, h, m = l, m, ( l + m ) // 2
		else:
			l, h, m = m, h, ( h + m ) // 2
	for i in range( l, h ):
		if i ** 2 == n:
			return i
	return -1

def find( n, base, e ):
	for i in range( 1, e ):
		if base % i == 0:
			phi = base // i
			a, b, c = 1, phi - n - 1, n
			judge = sqrt( b * b - 4 * a * c )
			if judge == -1:
				continue
			p, q = ( -b - judge ) // 2 // a, ( -b + judge ) // 2 // a
			if p * q == n:
				return ( p, q )

t = 0
while True:
	n, d, e = map( int, input().split() )
	if n == 0:
		break
	input()
	t, ans = t + 1, find( n, d * e - 1, e )
	print( 'Case #%d: %d %d' % ( t, ans[ 0 ], ans[ 1 ] ) )
