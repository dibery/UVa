for t in range( int( input() ) ):
	one, zero = map( int, input().split() )
	if zero * 2 < one:
		print( eval( '0b' + '101' * zero + '1' * ( one - zero * 2 ) ) )
	else:
		print( eval( '0b0' + '1' * ( one % 2 ) + '101' * ( one // 2 ) ) )
