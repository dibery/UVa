#include<cstdio>
#define N 2005
long long ans[ N ][ N ];

int main()
{
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
		{
			ans[ i ][ j ] = 1;
			if( i && j + 1 < N )
				ans[ i ][ j ] += ans[ i - 1 ][ j + 1 ];
			if( j )
				ans[ i ][ j ] += ans[ i ][ j - 1 ];
			ans[ i ][ j ] %= 9999959999ll;
		}
	for( int l, s; scanf( "%d %d", &l, &s ) && l + s; )
		printf( "%lld\n", ans[ l ][ s ] );
}
