from math import *

def to_str( num, base ):
	return [ num // base ** i % base for i in range( ceil( log( num ) / log( base ) + 1 ) ) ]

def to_int( s, base ):
	return sum( s[ i ] * base ** i for i in range( len( s ) ) )

for t in range( int( input() ) ):
	b1, b2, lower, upper = map( int, input().split() )
	found = False
	for i in range( upper - 1, lower, -1 ):
		if to_int( to_str( i, b1 ), b2 ) % i == 0:
			found = True
			print( i )
			break
	if not found:
		print( 'Non-existent.' )
