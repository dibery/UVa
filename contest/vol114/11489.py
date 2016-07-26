for t in range( int( input() ) ):
	n, count = input(), [ 0 ] * 3
	s = sum( map( int, n ) )
	for c in n:
		count[ int( c ) % 3 ] += 1
	print( 'Case %d: %s' % ( t + 1, 'S' if ( 1 if count[ s % 3 ] > 0 and s % 3 > 0 else 0 ) + count[ 0 ] % 2 == 1 else 'T' ) )
