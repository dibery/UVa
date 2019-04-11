def leap( y ):
	return y % 400 == 0 or ( y % 4 == 0 and y % 100 != 0 )

for t in range( int( input() ) ):
	d, m, y, dy = map( int, input().split() )
	bd = dy - y if ( m, d ) != ( 2, 29 ) else len( [ Y for Y in range( y + 4, dy + 1, 4 ) if leap( Y ) ] )
	print( 'Case %d: %d' % ( t + 1, bd ) )
