for i in range( int( input() ) ):
    n = int( input() )
    s = sum( f for f in range( 1, n ) if n % f == 0 )
    print( 'deficient' if s < n else ( 'perfect' if s == n else 'abundant' ) )
