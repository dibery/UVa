try:
    t = 1
    while True:
        brd, valid, done = [ [ j for j in input() ] for i in range( 5 ) ], True, False
        space = [ [ i, brd[ i ].index( ' ' ) ] for i in range( 5 ) if ' ' in brd[ i ] ][ 0 ]
        while not done:
            for act in input():
                if act == '0':
                    done = True
                    break
                if not valid:
                    continue
                try:
                    if act == 'A':
                        brd[ space[ 0 ] ][ space[ 1 ] ], brd[ space[ 0 ] - 1 ][ space[ 1 ] ] = brd[ space[ 0 ] - 1 ][ space[ 1 ] ], brd[ space[ 0 ] ][ space[ 1 ] ]
                        space[ 0 ] -= 1
                        valid &= space[ 0 ] >= 0
                    elif act == 'B':
                        brd[ space[ 0 ] ][ space[ 1 ] ], brd[ space[ 0 ] + 1 ][ space[ 1 ] ] = brd[ space[ 0 ] + 1 ][ space[ 1 ] ], brd[ space[ 0 ] ][ space[ 1 ] ]
                        space[ 0 ] += 1
                    elif act == 'L':
                        brd[ space[ 0 ] ][ space[ 1 ] ], brd[ space[ 0 ] ][ space[ 1 ] - 1 ] = brd[ space[ 0 ] ][ space[ 1 ] - 1 ], brd[ space[ 0 ] ][ space[ 1 ] ]
                        space[ 1 ] -= 1
                        valid &= space[ 1 ] >= 0
                    elif act == 'R':
                        brd[ space[ 0 ] ][ space[ 1 ] ], brd[ space[ 0 ] ][ space[ 1 ] + 1 ] = brd[ space[ 0 ] ][ space[ 1 ] + 1 ], brd[ space[ 0 ] ][ space[ 1 ] ]
                        space[ 1 ] += 1
                    else:
                        valid = False
                except IndexError:
                    valid = False
        if t > 1:
            print()
        print( 'Puzzle #%d:' % t )
        print( '\n'.join( ' '.join( brd[ i ] ) for i in range( 5 ) ) if valid else 'This puzzle has no final configuration.' )
        t += 1
except EOFError:
    pass
