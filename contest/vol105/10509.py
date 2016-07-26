def cbrt( n ):
	ans = int( n ** 0.334 )
	while ans ** 3 > n:
		ans -= 1
	return ans

while True:
	n = float( input() )
	if n == 0:
		break
	c = cbrt( n )
	print( '%.4f' % ( c + ( n - c ** 3 ) / 3 / c ** 2 ) )
