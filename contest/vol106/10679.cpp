#include<bits/stdc++.h>
using namespace std;

bool match( char* s, char* p )
{
	int fail[ 1001 ] = { -1 }, ls = strlen( s ), lp = strlen( p );

	if( lp > ls )
		return 0;
	for( size_t i = 1; i < lp; ++i )
	{
		int j = fail[ i-1 ];
		while( j >= 0 && p[ j+1 ] != p[ i ] )
			j = fail[ j ];
		fail[ i ] = j += p[ j+1 ] == p[ i ];
	}
	for( int i = 0, j = -1; i < ls; ++i )
	{
		while( j >= 0 && p[ j+1 ] != s[ i ] )
			j = fail[ j ];
		if( ( j += p[ j+1 ] == s[ i ] ) == lp-1 )
			return true;
	}
	return false;
}

int main()
{
	int t, size;
	char pattern[ 1001 ], s[ 100000 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		gets( s );
		scanf( "%d\n", &size );
		for( int i = 0; i < size; ++i )
		{
			gets( pattern );
			puts( match( s, pattern )? "y" : "n" );
		}
	}
}
