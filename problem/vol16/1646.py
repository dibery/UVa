line = [ 1, 1 ]
for i in range( 2, 10001 ):
    line.append( line[ i - 1 ] + line[ i - 2 ] )

try:
    while True:
        n = int( input() )
        print( line[ n ] + line[ n - 2 ] )
except:
    pass
