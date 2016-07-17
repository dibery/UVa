for t in range( int( input() ) ):
    battle, p, dp = int( input() ), float( input() ), []
    for i in range( battle + 1 ):
        dp.append( ( [ 0 ] * ( battle + 1 ) ).copy() )
    dp[ 0 ][ 0 ] = 1
    for i in range( battle + 1 ):
        for j in range( battle + 1 ):
            if i > 0 and j < battle:
                dp[ i ][ j ] += p * dp[ i - 1 ][ j ]
            if j > 0 and i < battle:
                dp[ i ][ j ] += ( 1 - p ) * dp[ i ][ j - 1 ]
    print( '%.2f' % sum( dp[ battle ][ :battle ] ) )
