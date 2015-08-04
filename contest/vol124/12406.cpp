#include<cstdio>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

bool conv( int n, int len, long long& C )
{
	char str[ 19 ] = { 0 };

	for( int i = 0; i < len; ++i )
		str[ i ] = ( ( n & 1 << i ) != 0 ) + '1';
	reverse( str, str + len );
	C = strtoll( str, NULL, 10 );

	return true;
}

int main()
{
	int t, len, pow;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		long long m = LLONG_MAX, M = LLONG_MIN, C;

		scanf( "%d %d", &len, &pow );
		for( int i = 0; i < 1 << len; ++i )
			if( conv( i, len, C ) && C % ( 1 << pow ) == 0 )
				m = min( m, C ), M = max( M, C );

		if( m == M )
			printf( "Case %d: %lld\n", n, m );
		else if( m == LLONG_MAX )
			printf( "Case %d: impossible\n", n );
		else
			printf( "Case %d: %lld %lld\n", n, m, M );
	}
}
