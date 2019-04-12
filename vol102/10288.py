from fractions import Fraction as f
import fileinput

ans = [ f() ]
for i in range( 1, 34 ):
    ans += [ ans[ -1 ] + f( 1, i ) ]
ans = [ i * ans[ i ] for i in range( len( ans ) ) ]

def proc( n ):
    if int( n ) == n:
        print( n )
    else:
        i, n, d = str( int( n ) ), str( n.numerator % n.denominator ), str( n.denominator )
        print( ' ' * len( i ) + ' ' + n )
        print( str( i ) + ' ' + '-' * len( d ) )
        print( ' ' * len( i ) + ' ' + d )

for i in fileinput.input():
    proc( ans[ int( i ) ] )
