def calc( mod, expo, limit = float( 'inf' ) ):
	if len( expo ) == 2:
		return expo[ 0 ] ** expo[ 1 ] % mod
	if len( expo ) == 1:
		return expo[ 0 ] % mod

	pmod, lookup, last = [ 1 ], { 1: 0 }, 1

	while last * expo[ 0 ] % mod not in lookup:
		pmod += last * expo[ 0 ] % mod
		last = last * expo[ 0 ] % mod
		lookup[ last ] = len( lookup )
	repeat = lookup[ last * expo % mod ]

try:
	for t in range( 100 ):
		s = list( map( int, input().split() ) )
		mod, size, exp = s[ 0 ], s[ 1 ], s[ 2: ]
		print( 'Case #%d: %d' % ( t + 1, calc( s[ 0 ], s[ 2 : ] ) ) )
except:
	pass
