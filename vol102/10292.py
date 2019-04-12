def sqrt( n ):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

for i in range( int( input() ) ):
    n = int( input() ) * 2
    sq = sqrt( n )
    print( 'Yes.' if sq * ( sq + 1 ) == n else 'No.' )
