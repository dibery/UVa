def more( result, check ):
    item = result[ 0 ][ 0 ]
    l, r = result[ 0 ][ 1:item+1 ], result[ 0 ][ item+1: ]
    if( check in l ):
        return result[ 1 ] == '>'
    elif( check in r ):
        return result[ 1 ] == '<'
    return result[ 1 ] == '='

def less( result, check ):
    item = result[ 0 ][ 0 ]
    l, r = result[ 0 ][ 1:item+1 ], result[ 0 ][ item+1: ]
    if( check in l ):
        return result[ 1 ] == '<'
    elif( check in r ):
        return result[ 1 ] == '>'
    return result[ 1 ] == '='

for t in range( int( input() ) ):
    input()
    coin, judge = map( int, input().split() )
    result = [ ( list( map( int, input().split() ) ), input() ) for i in range( judge ) ]

    sol = [ i for i in range( 1, coin + 1 ) if all( less( r, i ) for r in result ) or all( more( r, i ) for r in result ) ]

    if( t > 0 ):
        print()
    if( len( sol ) == 1 ):
        print( abs( sol[ 0 ] ) )
    else:
        print( 0 )

