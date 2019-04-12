#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	char str[ 256 ];
	scanf( "%d", &t );
	getchar();

	while( gets( str ) )
	{
		int len = 0, LIS[ 26 ] = { 0 }, times[ 26 ] = { 0 }, ans = 0, longest = 0, lis[ 26 ] = { 0 };
		sort( str, str + strlen( str ) );
		for( int i = 0; str[ i ]; ++i )
			if( isupper( str[ i ] ) && str[ i ] - 'A' + 1 != lis[ len-1 ] )
				lis[ len++ ] = str[ i ] - 'A' + 1;
		for( int i = 0; i < len; ++i )
			LIS[ i ] = times[ i ] = 1;
		for( int i = len-2; i >= 0; --i )
			for( int j = i+1; j < len; ++j )
				if( 5 * lis[ i ] <= 4 * lis[ j ] )
					if( LIS[ j ] + 1 > LIS[ i ] )
						LIS[ i ] = LIS[ j ] + 1, times[ i ] = times[ j ];
					else if( LIS[ j ] + 1 == LIS[ i ] )
						times[ i ] += times[ j ];
		for( int i = 0; i < len; ++i )
			longest = max( longest, LIS[ i ] );
		for( int i = 0; i < len; ++i )
			if( LIS[ i ] == longest )
				ans += times[ i ];
		printf( "%d %d\n", longest, ans );
	}
	return 0;
}