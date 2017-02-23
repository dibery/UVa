t = int( input() )
input()
for n in range( t ):
    P, T = map( int, input().split() )
    hear = [ 0 ] * P
    try:
        while True:
            s = input()
            if s == '':
                break
            a, b = map( int, s.split() )
            hear[ a - 1 ] |= 1 << b - 1
    except:
        pass
    if n > 0:
        print()
    print( len( set( hear ) ) )
