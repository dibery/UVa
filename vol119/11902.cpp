#include<cstdio>
const int N = 100;
int t, dim;

void dfs( int idx, int adj[][ N ], bool vis[], int skip = -1 )
{
	vis[ idx ] = true;
	for( int i = 0; i < dim; ++i )
		if( !vis[ i ] && adj[ idx ][ i ] && i != skip )
			dfs( i, adj, vis, skip );
}

int main()
{
	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int adj[ N ][ N ] = { { 0 } };
		bool vis[ N ][ N ] = { { false } }, origin[ N ] = { false };

		scanf( "%d", &dim );
		for( int i = 0; i < dim; ++i )
			for( int j = 0; j < dim; ++j )
				scanf( "%d", adj[ i ] + j );

		for( int i = 1; i < dim; ++i )
			dfs( 0, adj, vis[ i ], i );
		dfs( 0, adj, origin );

		char sep[ 300 ] = { '+' };
		for( int i = 1; i < dim * 2; ++i )
			sep[ i ] = '-';
		sep[ dim * 2 ] = '+';

		printf( "Case %d:\n", n );
		for( int i = 0; i < dim; ++i )
		{
			puts( sep );
			for( int j = 0; j < dim; ++j )
				printf( "|%c%s", origin[ j ] && !vis[ i ][ j ]? 'Y' : 'N', j == dim - 1? "|\n" : "" );
		}
		puts( sep );
	}
}
