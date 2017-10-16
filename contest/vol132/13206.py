for t in range( int( input() ) ):
	n, k = map( int, input().split() )
	print( sum( 6 * d * ( n - d + 1 ) for d in range( 1, k + 1 ) ) + n + 1 )
