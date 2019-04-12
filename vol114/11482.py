def tri( pad, qnt, size ): # front, back
	for i in range( 1, size ):
		s = ( size - i ) * ' ' + '/' + ( i - 1 ) * 2 * ' ' + '\\' + ' ' * ( size - i )
		print( pad + s * ( qnt - 1 ) + s.rstrip() )
	print( pad + ( '/' + ( size - 1 ) * 2 * '_' + '\\' ) * qnt )

c = 0
while True:
	size, layer = map( int, input().split() )
	if size == 0:
		break
	c += 1
	print( 'Triangular Museum %d' % c )
	for i in range( 1, layer + 1 ):
		tri( ' ' * size * ( layer - i ), i, size )
	print()
