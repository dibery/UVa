from math import log2 as log

frac = [ log( 1 - 1 / ( 1 << i + 1 ) ) for i in range( 10 ) ]
table = [ ( i, j, frac[ i ] + ( 1 << j ) - 1 ) for i in range( len( frac ) ) for j in range( 1, 31 ) ]

while True:
	f, e = map( float, input().split( 'e' ) )
	if f == e == 0:
		break
	log_value = log( f ) + log( 10 ) * e
	ans = [ ( i[ 0 ], i[ 1 ] ) for i in table if abs( log_value - i[ 2 ] ) < 1e-5 ][ 0 ]
	print( '%d %d' % ( ans[ 0 ], ans[ 1 ] ) )
