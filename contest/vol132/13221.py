import sys
for i in sys.stdin:
	i = int( i )
	print( ( i + 1 ) ** 2 // 2 - 1 )
