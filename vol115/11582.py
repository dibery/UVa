# TLE

def big_mod( base, exp, mod ):
	mul, ans = [ base % mod ], 1 if mod > 1 else 0
	for i in range( 1, 64 ):
		mul.append( mul[ -1 ] ** 2 % mod )
	for i in range( 64 ):
		if exp & 1 << i != 0:
			ans = ans * mul[ i ] % mod
	return ans

for t in range( int( input() ) ):
	base, exp, mod = map( int, input().split() )
	if mod == 1:
		print( 0 )
		continue
	cycle = [ 0, 1 ]
	while sum( cycle[ -2: ] ) % mod != 0 or cycle[ -1 ] != 1:
		cycle.append( sum( cycle[ -2: ] ) % mod )
	print( cycle[ big_mod( base, exp, len( cycle ) ) ] )
