# TLE
N = 100000
prime, layout = [ False ] * 2 + [ True ] + [ True, False ] * ( N - 3 ), [ [ 0 ], [ 0, 2 ], [ 0, 2, 5, 7 ] ]

for i in range( 3, int( N ** .5 ), 2 ):
	if prime[ i ]:
		for j in range( i ** 2, N, 2 * i ):
			prime[ j ] = False

for i in range( 3, N, 2 ):
	if prime[ i ]:
		layout += [ [ 0, i ] ]
		if prime[ i - 2 ]:
			layout += [ [ 0, 2, i ], [ 0, i - 2, i ] ]

for t in range( int( input() ) ):
	cell, coin = map( int, input().split() )
	ans, assign = 0, [ 1 ]
	for i in range( 1, 4 ):
		assign += [ assign[ -1 ] * ( coin - i ) // i ]
	for l in layout:
		ans += assign[ len( l ) - 1 ] * max( 0, cell - l[ -1 ] )
	print( 'Case %d: %d' % ( t + 1, ans ) )
