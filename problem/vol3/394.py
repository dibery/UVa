class array:
    def __init__( self, data ):
        self.base, self.size, self.dim = data[ : 3 ]
        self.low, self.high = data[ 3 : : 2 ][ : : -1 ], data[ 4 : : 2 ][ : : -1 ]

N, R = map( int, input().split() )
data = {}

for i in range( N ):
    s = input().split()
    data[ s[ 0 ] ] = array( list( map( int, s[ 1 : ] ) ) )

for i in range( R ):
    s = input().split()
    name, disp, D, cal = s[ 0 ], list( map( int, s[ 1 : ][ : : -1 ] ) ), data[ s[ 0 ] ].dim, data[ s[ 0 ] ]

    C = [ data[ name ].size ] * D
    for j in range( 1, D ):
        C[ j ] = C[ j - 1 ] * ( cal.high[ j - 1 ] - cal.low[ j - 1 ] + 1 )

    ans = sum( C[ j ] * disp[ j ] for j in range( D ) ) \
        + data[ name ].base \
        - sum( C[ j ] * cal.low[ j ] for j in range( D ) )
    print( s[ 0 ] + str( disp[ : : -1 ] ) + ' = ' + str( ans ) )
