for t in range( int( input() ) ):
    n = int( input() )
    print( 66 ** n % 100 if n < 2 else '59371'[ ( n - 2 ) % 5 ] + '6' )
