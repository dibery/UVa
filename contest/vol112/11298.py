import sys
for i in sys.stdin:
	print( 0 if int( i ) % 3 != 0 or int( i ) <= 0 else 1 )
