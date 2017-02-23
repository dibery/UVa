from curses.ascii import *

fib = [ 1, 2 ]
for i in range( 2, 50 ):
    fib.append( fib[ i - 1 ] + fib[ i - 2 ] )

for t in range( int( input() ) ):
    length = int( input() )
    idx = list( map( int, input().split() ) )
    cipher = [ c for c in input() if isupper( c ) ]
    s = [ ' ' ] * ( fib.index( max( idx ) ) + 1 )
    for i in range( length ):
        s[ fib.index( idx[ i ] ) ] = cipher[ i ]
    print( ''.join( s ) )
