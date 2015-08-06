#include<bits/stdc++.h>
using namespace std;

bool sp( int page[], int b, int e, int m, long long lim )
{
	for( long long i = b, sum = 0; i < e && m; ++i )
	{
		sum += page[ i ];
		if( i != e-1 && sum + page[ i+1 ] > lim )
			sum = 0, --m;
	}
	return m > 0;
}

int main()
{
	int book, man, page[ 500 ], t;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &book, &man );
		for( int i = 0; i < book; ++i )
			scanf( "%d", page + i );
		long long dp[ 500 ][ 500 ] = { { *page } };

		fill( dp[ 1 ], dp[ man ], LLONG_MAX );
		for( int i = 1; i < book; ++i )
			dp[ 0 ][ i ] = dp[ 0 ][ i-1 ] + page[ i ];
		for( int m = 1; m < man; ++m )
			for( int b = m; b < book; ++b )
				for( int now = m; now <= b; ++now )
					dp[ m ][ b ] = min( dp[ m ][ b ], max( dp[ 0 ][ b ] - dp[ 0 ][ now-1 ], dp[ m-1 ][ now-1 ] ) );
		for( int i = 0, have = man; i < book; ++i )
		{
			printf( "%d%c", page[ i ], i == book-1? '\n' : ' ' );
			if( i != book-1 && ( book - i <= have || sp( page, i+1, book, have-1, dp[ man-1 ][ book-1 ] ) ) )
				printf( "/ " ), --have;
		}
	}
}
