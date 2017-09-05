# TLE
try:
    case = 0
    while True:
        case += 1
        time = sorted( list( map( int, input().split() ) ) )
        shift = time[ 0 ] - 5
        print( 'Set', case, end = '' )
        for s in range( shift, 3600 ):
            if all( s % ( 2 * time[ i ] ) < time[ i ] - 5 for i in range( len( time ) ) ):
                print( ' synchs again at %d minute(s) and %d second(s) after all turning green.' % ( s / 60, s % 60 ) )
                break
        if s == 3600:
            print( ' is unable to synch after one hour.' )
except:
    pass
