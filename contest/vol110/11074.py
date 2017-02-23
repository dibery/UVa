t = 0
while True:
	sq, thick, grid = map( int, input().split() )
	if sq == 0:
		break
	top_border = '*' * ( thick * ( grid + 1 ) + sq * grid )
	mid = ( '*' * thick + '.' * sq ) * grid + '*' * thick
	t += 1
	print( 'Case %d:' % t )
	print( '\n'.join( top_border for i in range( thick ) ) )
	for i in range( grid ):
		print( '\n'.join( mid for i in range( sq ) ) )
		print( '\n'.join( top_border for i in range( thick ) ) )
	print()
