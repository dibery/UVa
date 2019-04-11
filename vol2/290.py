def to_str( num, base ):
	s, literal = '', '0123456789abcdef'
	while num > 0:
		s += literal[ num % base ]
		num //= base
	return s[ : : -1 ]

def f( s, base ):
	try:
		n, proc = int( s, base ), [ s ]
	except:
		return '?'
	while proc[ -1 ][ : : -1 ] != proc[ -1 ]:
		proc.append( to_str( int( proc[ -1 ], base ) + int( proc[ -1 ][ : : -1 ], base ), base ) )
	return str( len( proc ) - 1 )

try:
	while True:
		s = input()
		print( ' '.join( f( s, i ) for i in range( 15, 1, -1 ) ) )
except EOFError:
	pass
