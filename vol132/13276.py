# TLE
from math import ceil

def ans( E, P, K, R ):
	if P * K >= E:
		return ceil( E / P )
	elif P * K <= R:
		return -1
	else:
		round = ceil( ( E - P * K ) / ( P * K - R ) )
		return round * K + ceil( ( E - ( P * K - R ) * round ) / P )

for x in range( int( input() ) ):
	E, P, K, R = map( int, input().split() )
	print( 'Case %d: %d' % ( x + 1, ans( E, P, K, R ) ) )
