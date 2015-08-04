#include<bits/stdc++.h>
#define I type == 'B'? 0 : i
#define J type == 'B'? i : 0
#define NOW brd[ I ][ J ]

bool dfs( char brd[][ 99 ], int size, int i, int j, bool vis[ 99 ][ 99 ][ 2 ], bool last, char type )
{
	if( vis[ i ][ j ][ last ] || vis[ i ][ j ][ true ] )
		return false;
	vis[ i ][ j ][ last ] = true;
	if( type == 'B' && i == size-1 || type == 'W' && j == size-1 )
		return true;

	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( m >= 0 && m < size && n >= 0 && n < size && m == i ^ n == j && ( brd[ m ][ n ] == type || last && brd[ m ][ n ] == 'U' ) )
				if( dfs( brd, size, m, n, vis, brd[ m ][ n ] == 'U'? false : last, type ) )
					return true;
	return false;
}

bool check( char brd[][ 99 ], int size, char type, bool last )
{
	bool vis[ 99 ][ 99 ][ 2 ] = { { { false } } };

	for( int i = 0; i < size; ++i )
		if( NOW == type || last && NOW == 'U' )
			if( dfs( brd, size, I, J, vis, NOW == 'U'? false : last, type ) )
				return true;
	return false;
}

int main()
{
	for( int size; scanf( "%d\n", &size ) && size; )
	{
		char brd[ 99 ][ 99 ];

		for( int i = 0; i < size; ++i )
			gets( brd[ i ] );

		if( check( brd, size, 'W', false ) )
			puts( "White has a winning path." );
		else if( check( brd, size, 'B', false ) )
			puts( "Black has a winning path." );
		else if( check( brd, size, 'W', true ) )
			puts( "White can win in one move." );
		else if( check( brd, size, 'B', true ) )
			puts( "Black can win in one move." );
		else
			puts( "There is no winning path." );
	}
}
