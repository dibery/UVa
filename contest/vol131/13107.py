try:
	while True:
		lookup, use = [ 0 ] * 26, [ 1, 5, 3, 4, 2, 9, 7, 8, 6, 10, 11, 15, 13, 14, 12, 19, 17, 18, 16, 50, 51, 55, 53, 54, 52, 59 ]
		for c in input():
			c = ord( c ) - ord( 'a' )
			if lookup[ c ] == 0:
				lookup[ c ] = use.pop( 0 )
			print( lookup[ c ], end = '' )
		print()
except:
	pass
