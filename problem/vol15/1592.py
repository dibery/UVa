import sys

for x in sys.stdin:

	row = int( x.split()[ 0 ] )
	col = int( x.split()[ 1 ] )
	table = {}
	ok = True

	for i in range( row ):
		x = input().split( ',' )
		if ok:
			for m in range( len( x ) ):
				for n in range( m + 1, len( x ) ):
					if ( x[ m ], x[ n ], m, n ) in table and ok:
						ok = False
						print( "NO" )
						print( table[ ( x[ m ], x[ n ], m, n ) ] + ' ' + str( i + 1 ) )
						print( str( m + 1 ) + ' ' + str( n + 1 ) )
					table[ ( x[ m ], x[ n ], m, n ) ] = str( i + 1 )
	if ok:
		print( "YES" );
