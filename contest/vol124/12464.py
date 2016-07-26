while True:
	a, b, n = map( int, input().split() )
	if a == 0:
		break
	print( [ a, b, ( 1 + b ) // a, ( 1 + a + b ) // a // b, ( 1 + a ) // b ][ n % 5 ] )
