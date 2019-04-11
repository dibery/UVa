for t in range( int( input() ) ):
	a, b = map( int, input().split() )
	if a & ~b != 0:
		print( -1 )
	else:
		base, assign = a & b, ~a & b
		lower = int( '{0:b}'.format( assign ).replace( '1', '0', 1 ), 2 )
		print( lower | base, assign - lower | base )
