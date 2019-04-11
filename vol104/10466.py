from math import *
try:
	while True:
		star, time = map( int, input().split() )
		data = [ list( map( int, input().split() ) ) for i in range( star ) ]
		print( ' '.join( '%.4f' % hypot( sum( s[ 0 ] * cos( time / s[ 1 ] * pi * 2 ) for s in data[ : i+1 ] ), sum( s[ 0 ] * sin( time / s[ 1 ] * 2 * pi ) for s in data[ : i+1 ] ) ) for i in range( star ) ) )
except:
	pass