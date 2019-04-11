for t in range( int( input() ) ):
	a, b = map( int, input().split() )
	print( b * 10 // ( b - a ) )
