# Gets TLE
for i in range( int( input() ) ):
    island, small = map( int, input().split() )
    p, q, r, x, y, z = map( int, input().split() )
    n = [ p * i * i + q * i + r for i in range( 1, island + 1 ) ]
    s = { ( x * i * i + y * i + z ) % island + 1 for i in range( 1, small + 1 ) }
    root = min( [ n[ i-1 ] for i in set( range( 1, island + 1 ) ) - s ] )
    print( 'Case %d: %d' % ( i + 1, sum( n, -root ) * root ) )
