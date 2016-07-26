# TLE
def ok( x, y, dim, i ):
	return min( x, y, dim - x - 1, dim - y - 1 ) == i

for t in range( int( input() ) ):
	dim, brd = int( input() ), []
	for i in range( dim ):
		brd.append( input().split() )
	for r in range( ( dim + 1 ) // 2 ):
		s = list( map( int, input().split() ) )
		for i in s[ 1 : ]:
			if i == 1:
				for x in range( dim // 2 ):
					for y in range( dim ):
						if ok( x, y, dim, r ):
							brd[ x ][ y ], brd[ dim - x - 1 ][ y ] = brd[ dim - x - 1 ][ y ], brd[ x ][ y ]
			elif i == 2:
				for x in range( dim ):
					for y in range( dim // 2 ):
						if ok( x, y, dim, r ):
							brd[ x ][ y ], brd[ x ][ dim - y - 1 ] = brd[ x ][ dim - y - 1 ], brd[ x ][ y ]
			elif i == 3:
				for x in range( dim ):
					for y in range( x, dim ):
						if ok( x, y, dim, r ):
							brd[ x ][ y ], brd[ y ][ x ] = brd[ y ][ x ], brd[ x ][ y ]
			else:
				for x in range( dim ):
					for y in range( dim - x ):
						if ok( x, y, dim, r ):
							brd[ x ][ y ], brd[ dim - y - 1 ][ dim - x - 1 ] = brd[ dim - y - 1 ][ dim - x - 1 ], brd[ x ][ y ]
	for s in brd:
		print( ' '.join( s ) )
