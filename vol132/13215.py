for t in range( int( input() ) ):
    corner, area, geo = 0, 0., [ 0 ] * 4
    for n in range( int( input() ) ):
        s = input().split()
        l = int( s[ 1 ] )
        geo[ corner ] += l
        if s[ 0 ] == 'C' and n > 0:
            corner += 1
            geo[ corner ] += l
        area -= l ** 2 * ( 3 ** .5 / 4 if s[ 0 ] == 'T' else 1 )
    print( '%.4f' % ( area + geo[ 0 ] * geo[ 1 ] ) )
