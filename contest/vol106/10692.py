from math import *

def calc( mod, expo ):
	if len( expo ) == 2:
		return expo[ 0 ] ** expo[ 1 ] % mod
	if len( expo ) == 1:
		return expo[ 0 ] % mod
	if len( expo ) == 0:
		return 1 % mod

	first = 1 % mod
	pmod, lookup, last = [ first ], { first: 0 }, first

	while last * expo[ 0 ] % mod not in lookup:
		last = last * expo[ 0 ] % mod
		pmod.append( last )
		lookup[ last ] = len( lookup )
	repeat = lookup[ last * expo[ 0 ] % mod ]

	cycle = len( pmod ) - repeat
	ans = calc( cycle, expo[ 1: ] )
	if larger( expo[ 1: ], cycle ):
		while repeat % cycle != ans % cycle:
			repeat += 1
		return pmod[ repeat ]
	return pmod[ ans ]

def larger( power, num ):
	if num < 1:
		return True
	if len( power ) == 1:
		return num < power[ 0 ]
	return larger( power[ 1: ], log( num, power[ 0 ] ) )

try:
	for t in range( 100 ):
		s = list( map( int, input().split() ) )
		mod, exp = s[ 0 ], s[ 2: ]
		while 1 in exp:
			exp.pop()
		print( 'Case #%d: %d' % ( t + 1, calc( mod, exp ) ) )
except:
	pass
