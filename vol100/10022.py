from math import *

def find( start, end ):
    start, end = min( start, end ), max( start, end )
    slayer, elayer = int( sqrt( start - 1 ) + 1 ), int( sqrt( end - 1 ) + 1 )
    scol, ecol = ( slayer * 2 - 1 ) - ( slayer ** 2 - start ), ( elayer * 2 - 1 ) - ( elayer ** 2 - end )
    sup, eup = slayer % 2 != start % 2, elayer % 2 != end % 2
    layer_dist = ( elayer - slayer ) * 2
    if sup and not eup:
        layer_dist += 1
    elif not sup and eup:
        layer_dist -= 1
    col_dist = abs( ecol - scol )
    if ecol >= scol:
        return max( layer_dist, col_dist )
    else:
        return find( start + slayer * 2, end ) + 1

for t in range( int( input() ) ):
    input()
    start, end = map( int, input().split() )
    if t > 0:
        print()
    print( find( start, end ) )
