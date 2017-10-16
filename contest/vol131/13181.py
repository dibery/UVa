try:
	while True:
		bed = input()
		man = [ i for i in range( len( bed ) ) if bed[ i ] == 'X' ]
		ans = max( man[ 0 ], len( bed ) - man[ -1 ] - 1 ) - 1
		if len( man ) > 1:
			print( max( ans, max( ( man[ i + 1 ] - man[ i ] ) // 2 - 1 for i in range( len( man ) - 1 ) ) ) )
		else:
			print( ans )
except:
	pass
