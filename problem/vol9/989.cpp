#include<cstdio>

bool ok( int brd[ 9 ][ 9 ], int size, int Try, int pos )
{
	int len = size * size;
	for( int i = 0; i < len; ++i )
		if( brd[ pos / len ][ i ] == Try && i != pos % len || brd[ i ][ pos % len ] == Try && i != pos / len )
			return false;
	for( int X = pos / len / size * size, Y = pos % len / size * size, i = X; i < X + size; ++i )
		for( int j = Y; j < Y + size; ++j )
			if( brd[ i ][ j ] == Try && i * len + j != pos )
				return false;
	return true;
}

bool solve( int brd[ 9 ][ 9 ], bool fix[ 9 ][ 9 ], int size, int pos = 0 )
{
	int len = size * size;

	if( pos == len * len )
		return true;
	if( fix[ pos / len ][ pos % len ] && ok( brd, size, brd[ pos / len ][ pos % len ], pos ) )
		return solve( brd, fix, size, pos + 1 );
	else if( !fix[ pos / len ][ pos % len ] )
		for( int i = 1; i <= len; ++i )
			if( ok( brd, size, i, pos ) )
			{
				brd[ pos / len ][ pos % len ] = i;
				if( solve( brd, fix, size, pos + 1 ) )
					return true;
				brd[ pos / len ][ pos % len ] = 0;
			}
	return false;
}

int main()
{
	for( int size, brd[ 9 ][ 9 ], first = 1; scanf( "%d", &size ) == 1; )
	{
		bool fixed[ 9 ][ 9 ] = { { false } }, valid = true;

		for( int i = 0; i < size * size; ++i )
			for( int j = 0; j < size * size; ++j )
			{
				scanf( "%d", brd[ i ] + j );
				fixed[ i ][ j ] = brd[ i ][ j ];
				valid &= brd[ i ][ j ] > 0 && brd[ i ][ j ] <= size * size;
			}

		if( first )
			first = 0;
		else
			puts( "" );
		if( solve( brd, fixed, size ) )
			for( int i = 0; i < size * size; ++i )
				for( int j = 0; j < size * size; ++j )
					printf( "%d%c", brd[ i ][ j ], j == size * size - 1? '\n' : ' ' );
		else
			puts( "NO SOLUTION" );
	}
}
