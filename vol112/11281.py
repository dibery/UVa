from string import ascii_uppercase as upper
from math import *

class triangle:
    def __init__( self ):
        self.a, self.b, self.c = sorted( list( map( float, input().split() ) ) )
    def cc( self ): # Circumscribed circle
        a, b, c = self.a, self.b, self.c
        if a*a + b*b < c*c:
            return c - 1e-9
        return a / ( 1 - ( ( b*b + c*c - a*a ) / 2 / b / c ) ** 2 ) ** .5 - 1e-9

input()
r = list( map( float, input().split() ) )
for x in range( int( input() ) ):
    t = triangle()
    fit = [ str( i + 1 ) for i in range( len( r ) ) if t.cc() <= r[ i ] ]
    if len( fit ) == 0:
        print( 'Peg %s will not fit into any holes' % upper[ x ] )
    else:
        print( 'Peg %s will fit into hole(s): %s' % ( upper[ x ], ' '.join( fit ) ) )
