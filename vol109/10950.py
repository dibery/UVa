for t in range( 1, 501 ):
	n, lookup = int( input() ), {}
	if( n == 0 ):
		break
	for i in range( n ):
		char, code = input().split()
		lookup[ char ] = code
	cipher = input()
	ans = [ set() for i in cipher ] + [ set( [ "" ] ) ]
	for i in range( len( cipher ) )[ : : -1 ]:
		for c in lookup:
			if cipher[ i : ].startswith( lookup[ c ] ):
				ans[ i ] |= set( c + n for n in ans[ i + len( lookup[ c ] ) ] )
		if cipher[ i ] == '0' and len( ans[ i + 1 ] - { "" } ) > 0:
			ans[ i ] |= ans[ i + 1 ]
	print( 'Case #%d' % t )
	print( '\n'.join( sorted( ans[ 0 ] )[ : 100 ] ) + '\n' )
