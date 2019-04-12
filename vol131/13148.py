special = set( i ** 2 for i in range( 1, 10000 ) ) & set( i ** 3 for i in range( 1, 465 ) )
while True:
    s = int( input() )
    if s == 0:
        break
    print( 'Special' if s in special else 'Ordinary' )
