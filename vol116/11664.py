dx, dy = [ -1, 0, 1, 0 ], [ 0, 1, 0, -1 ]

def run( brd, x, y, dim, dir = 0 ):
	try:
		while True:
			assert 0 <= x < dim and 0 <= y < dim
			if ( x, y ) == ( 0, dim - 1 ):
				return 'Yes'
			dir = ( dir + ( 1 if brd[ x ][ y ] else 3 ) ) % 4
			brd[ x ][ y ] = not brd[ x ][ y ]
			x, y = x + dx[ dir ], y + dy[ dir ]
	except:
		return 'Kaputt!'

while True:
	dim, rep, x, y = map( int, input().split() )
	if dim == 0:
		break
	brd = [ [ rep & 1 << i * dim + j != 0 for j in range( dim )[::-1] ] for i in range( dim ) ]
	print( run( brd, dim - y, x - 1, dim ) )
