#include<cstdio>

int main()
{
	int G[ 1000 ][ 1000 ] = { { 0 } }, t, size;

	for( scanf( "%d", &t ); t--; )
	{
		int ans = 0;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j < size; ++j )
				scanf( "%d", G[ i ] + j );
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j < size; ++j )
				for( int k = j + 1; k < size; ++k )
					ans += G[ i ][ j ] == G[ i ][ k ] && G[ i ][ k ] == G[ j ][ k ];
		printf( "%d\n", ans );
	}
}
