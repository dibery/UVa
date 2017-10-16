# TLE
while True:
    s = input().split()
    if s == [ '0' ]:
        break
    for i in range( len( s ) ):
        try:
            n, cnt = int( s[ i ] ), 0
            for j in range( i - 1, -1, -1 ):
                if s[ j ] != '#':
                    cnt += 1
                if cnt == n:
                    s[ i ] = str( i - j )
                    break
        except:
            pass
    print( ' '.join( s ) )
