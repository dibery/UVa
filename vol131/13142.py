for t in range( int( input() ) ):
    time, speed, dist = map( int, input().split() )
    if dist <= 0:
        print( 'Add %d tons' % ( -dist * 1e6 / time // 86400 ) )
    elif dist * 1000000 < time * 86400:
        print( 'Add 0 tons' )
    else:
        print( 'Remove %d tons' % ( dist * 1e6 / time // 86400 ) )
