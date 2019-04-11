from math import factorial as f

fact, ans, mod = [ f( i ) for i in range( 1001 ) ], [ 1 ] + [ 0 ] * 1000, 10056

for horse in range( 1, 1001 ):
    comb = horse
    for first in range( 1, horse + 1 ):
        ans[ horse ] = ( ans[ horse ] + comb * ans[ horse - first ] ) % mod
        comb = comb * ( horse - first ) // ( first + 1 )

for t in range( int( input() ) ):
    print( 'Case %d: %d' % ( t + 1, ans[ int( input() ) ] ) )
