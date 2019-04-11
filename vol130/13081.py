def get( i ):
    if i % 2 == 0:
        return i // 4 * 4 + 1 + i % 4 // 2
    else:
        return i % 4 // 2

for i in range( int( input() ) ):
    L, R = map( int, input().split() )
    if R - L >= 4:
        print( 0 )
    else:
        ans = get( R )
        for j in range( L, R ):
            ans &= get( j )
        print( ans )
