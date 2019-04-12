from fractions import Fraction

def find( N, R ):
	D, U = int( '9' * len( R ) + '0' * len( N ) ), int( N + R ) - ( int( N ) if N != '' else 0 )
	return Fraction( U, D )

while True:
	s = input()
	if s == '0':
		break
	s = s.split( '.' )[ 1 ]
	for i in range( len( s ) ):
		f = find( s[ : i ], s[ i : ] )
		if 'ans' not in locals() or ans.denominator > f.denominator:
			ans = f
	print( '%d/%d' % ( ans.numerator, ans.denominator ) )
	del ans
