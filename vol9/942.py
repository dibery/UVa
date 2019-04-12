for t in range( int( input() ) ):
    up, down = map( int, input().split() )
    q, pos, r, idx = [], [ -1 ] * down, up % down, 0
    print( '%d.' % ( up // down ), end = '' )
    while pos[ r ] == -1 and r > 0:
        pos[ r ] = idx
        idx += 1
        q.append( r * 10 // down )
        r = r * 10 % down
    if r == 0:
        for n in q:
            print( n, end = '' )
        if up % down == 0:
            print( 0 )
        else:
            print()
    else:
        for i in range( pos[ r ] ):
            print( q[ i ], end = '' )
        print( '(', end = '' )
        for i in range( pos[ r ], len( q ) ):
            print( q[ i ], end = '' )
        print( ')' )
