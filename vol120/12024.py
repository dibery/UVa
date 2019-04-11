from math import factorial as fact

for t in range( int( input() ) ):
    n, ans = int( input() ), 0
    for i in range( n + 1 ):
        ans += fact( n ) / fact( i ) // fact( n - i ) * ( -1 ) ** i * fact( n - i )
    print( '%d/%d' % ( ans, fact( n ) ) )
