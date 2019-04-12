from math import copysign as cs
while True:
	t = int( input() )
	if t == 0:
		break
	s = input().split()
	pay, get = float( s[ 0 ] ), list( map( float, s[ 1 : ] ) )

	u, l = ( 10000, 0 ) if sum( get ) + pay >= 0 else ( 0, -1 )
	m = ( u + l ) / 2
	while u - l > 1e-4:
		if sum( get[ i ] / ( 1 + m ) ** ( i + 1 ) for i in range( len( get ) ) ) + pay > 0:
			l, m = m, ( u + m ) / 2
		else:
			u, m = m, ( l + m ) / 2
	
	print( '%.2f' % ( m + cs( 1e-9, m ) ) )
