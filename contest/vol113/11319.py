for t in range( int( input() ) ):
	fx, coef = [ int( input() ) for i in range( 1500 ) ], []
	input()
	n = fx[ 1000 ]
	for i in range( 7 ):
		coef.append( n % 1001 )
		n = ( n - n % 1001 ) // 1001
	if fx == [ sum( coef[ i ] * p ** i for i in range( 7 ) ) for p in range( 1, 1501 ) ]:
		print( ' '.join( map( str, coef ) ) )
	else:
		print( 'This is a smart sequence!' )
