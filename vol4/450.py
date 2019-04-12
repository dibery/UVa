class employee:
	def __init__( self, data, dept ):
		self.data = data.split( ',' ) + [ dept ]
	def __lt__( self, rhs ):
		return self.data[ 2 ] < rhs.data[ 2 ]
	def __str__( self ):
		data = self.data
		return '-' * 40 + '\n' + ' '.join( data[ : 3 ] ) + '\n' + data[ 3 ] + '\nDepartment: ' + data[ 7 ] + '\nHome Phone: ' + data[ 4 ] + '\nWork Phone: ' + data[ 5 ] + '\nCampus Box: ' + data[ 6 ]

member = []

for dept in range( int( input() ) ):
	dept_name = input()
	try:
		while True:
			s = input()
			if s == '':
				break
			member.append( employee( s, dept_name ) )
	except EOFError:
		pass

for m in sorted( member ):
	print( m )
