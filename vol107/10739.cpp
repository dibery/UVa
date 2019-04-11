#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;
int dist[ N ][ N ];

int main()
{
	int T;
	char s[ N ];

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%s", s + 1 ); ++t )
	{
		int len = strlen( s + 1 ), ans = 1e6;
		for( int i = 1; i <= len; ++i )
			dist[ 0 ][ i ] = dist[ i ][ 0 ] = i;
		for( int i = 1; i <= len; ++i )
			for( int j = 1; j <= len; ++j )
				if( s[ i ] == s[ len - j + 1 ] )
					dist[ i ][ j ] = dist[ i - 1 ][ j - 1 ];
				else
					dist[ i ][ j ] = 1 + min( dist[ i - 1 ][ j ], min( dist[ i ][ j - 1 ], dist[ i - 1 ][ j - 1 ] ) );
		for( int i = 1; i <= len; ++i )
			ans = min( ans, min( dist[ i ][ len - i ], dist[ i ][ len - i + 1 ] ) );
		printf( "Case %d: %d\n", t, ans );
	}
}
