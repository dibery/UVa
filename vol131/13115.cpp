#include<cstdio>
#include<cstring>
#include<cmath>
const int sq[] = { 0, 1, 4, 9, 16, 25 };
int brd[ 25 ][ 25 ], dim;

bool check( int r, int c )
{
	int C = brd[ r ][ c ], part = sqrt( dim ) + .1;
	for( int i = 0; i < dim; ++i )
		if( brd[ r ][ i ] == C && i != c || brd[ i ][ c ] == C && i != r )
			return false;
	for( int i = r / part * part; i <= r / part * part + 1; ++i )
		for( int j = c / part * part; j <= c / part * part + 1; ++j )
			if( brd[ i ][ j ] == C && ( i != r || j != c ) )
				return false;
	return true;
}

int main()
{
	for( scanf( "%*d" ); scanf( "%d", &dim ) == 1; )
	{
		bool ok = true;
		for( int i = 0; i < dim; ++i )
			for( int j = 0; j < dim; ++j )
				scanf( "%d", brd[ i ] + j ), ok &= check( i, j );
		puts( ok? "yes" : "no" );
		memset( brd, 0, sizeof( brd ) );
	}
}
