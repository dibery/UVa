for t in range( int( input() ) ):
	r, c, m, n = map( int, input().split() )
	s = ''.join( [ input() for i in range( r ) ] )
	stat = [ s.count( c ) for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' ]
	M = max( stat )
	print( 'Case %d: %d' % ( t + 1, sum( [ x * m if x == M else x * n for x in stat ] ) ) )
