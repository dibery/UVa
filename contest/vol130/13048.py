for t in range( int( input() ) ):
    road = input()
    ans = 0
    for i in range( len( road ) ):
        ok = road[ i ] == '-'
        if i < len( road ) - 2:
            ok &= road[ i + 2 ] != 'B'
        if i < len( road ) - 1:
            ok &= road[ i + 1 ] != 'B' and road[ i + 1 ] != 'S'
        if i >= 1:
            ok &= road[ i - 1 ] != 'S'
        if ok:
            ans += 1
    print( 'Case %d: %d' % ( t + 1, ans ) )
