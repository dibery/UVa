for t in range( int( input() ) ):
	s = ' '.join( input().split() )
	print( 'Y' if s == '1 2 3 4 5' or s == '2 3 4 5 6' else 'N' )
