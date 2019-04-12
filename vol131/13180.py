while True:
	pearl, ans = sorted( list( map( int, input().split() ) )[ : -1 ], reverse = True ), []
	if len( pearl ) == 0:
		break
	if len( pearl ) % 2 == 0:
		print( 'NO' )
	else:
		ans.append( pearl[ 0 ] )
		pearl.pop( 0 )
		while pearl != []:
			ans = [ pearl[ 0 ] ] + ans + [ pearl[ 1 ] ]
			pearl = pearl[ 2 : ]
		print( ' '.join( map( str, ans ) ) if list( reversed( ans ) ) == ans else 'NO' )
