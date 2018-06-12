from math import inf

for t in range( int( input() ) ):
    cap, tem = map( int, input().split() )
    jar, best = int( input() ), inf
    l = [ tuple( map( int, input().split() ) ) for i in range( jar ) ]
    jcap, jheat = [ a[ 0 ] for a in l ], [ a[ 0 ] * a[ 1 ] for a in l ]

    for i in range( jar ):
        c, h = 0, 0
        for j in range( i, jar ):
            c += jcap[ j ]
            h += jheat[ j ]
            if c >= cap / 2 and c <= cap and h / c <= tem + 5 and abs( h / c - tem ) < abs( best - tem ):
                best = h / c
                ans = ( i, j )
    if 'ans' in locals():
        print( '%d %d' % ( ans[ 0 ], ans[ 1 ] ) )
        del ans
    else:
        print( 'Not possible' )
