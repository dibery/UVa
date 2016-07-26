note = [ 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B' ]
diff = [ 0, 2, 4, 5, 7, 9, 11, 12 ]
scale = [ [ ( i + diff[ j ] ) % 12 for j in range( 8 ) ] for i in range( 12 ) ]

while True:
	s = input()
	if s == 'END':
		break
	s = [ note.index( n ) for n in s.split() ]
	print( ' '.join( [ note[ i ] for i in range( 12 ) if all( [ n in scale[ i ] for n in s ] ) ] ) )
