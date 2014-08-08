#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char name[ 30 ];
	int len;

	while( gets( name ) && ( len = strlen( name ) ) )
	{
		char perm[ 21 ][ 30 ] = { 0 };
		int val[ 21 ] = { 0 }, index = 0, diff = -1;
		strcpy( perm[ 10 ], name );

		for( int i = 9; i >= 0; --i )
		{
			prev_permutation( name, name+len );
			strcpy( perm[ i ], name );
		}
		strcpy( name, perm[ 10 ] );
		for( int i = 11; i <= 20; ++i )
		{
			next_permutation( name, name+len );
			strcpy( perm[ i ], name );
		}

		for( int i = 0; i <= 20; ++i )
		{
			val[ i ] = abs( perm[ i ][ 1 ] - perm[ i ][ 0 ] );
			for( int j = 2; perm[ i ][ j ]; ++j )
				val[ i ] = min( val[ i ], abs( perm[ i ][ j ] - perm[ i ][ j-1 ] ) );
			if( val[ i ] > diff )
			{
				diff = val[ i ];
				index = i;
			}
		}
		printf( "%s%d\n", perm[ index ], diff );
	}
}
