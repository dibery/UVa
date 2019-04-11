# TLE
for t in range( int( input() ) ):
	n, m, a, b = map( float, input().split() )
	diff = ( m * ( a + b ) - n * a ) / b
	print( 'Case #%d: %s' % ( t + 1, '{:.2f}'.format( diff ) if 0 <= diff <= 10 else 'Impossible' ) )
