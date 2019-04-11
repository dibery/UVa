from math import *

fact = [ factorial( i ) for i in range( 141 ) ]
for i in range( int( input() ) ):
    subject, total, ok = map( int, input().split() )
    if ok * subject > total:
        print( 0 )
    else:
        m, n = total - subject * ok, subject
        print( fact[ m + n - 1 ] // fact[ m ] // fact[ n - 1 ] )
