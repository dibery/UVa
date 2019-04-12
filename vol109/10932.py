try:
	while True:
		S = input()
		if '=' in S:
			exec( S )
		else:
			print( eval( '"{:.2f}".format(' + S + ')' ) )
except:
	pass
