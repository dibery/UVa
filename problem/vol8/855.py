for t in range( int( input() ) ):
	s, a, f = map( int, input().split() )
	loc = [ tuple( map( int, input().split() ) ) for i in range( f ) ]
	x, y = sorted( [ i[ 0 ] for i in loc ] ), sorted( [ i[ 1 ] for i in loc ] )
	print( '(Street: %d, Avenue: %d)' % ( x[ ( f - 1 ) // 2 ], y[ ( f - 1 ) // 2 ] ) )
