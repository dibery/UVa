# TLE
method = [ ( n + 2 ) * ( n + 1 ) // 2 for n in range( 10000 ) ]
for t in range( int( input() ) ):
	n = int( input() )
	print( method.index( n ) if n in method else 'No solution' )
