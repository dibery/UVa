#include<cstdio>
#include<algorithm>
#include<numeric>
#include<cstring>

int sol[ 83 ][ 11 ][ 83 ][ 82 ], pow10[ 10 ] = { 1 }; // [N][#][S][M]

int calc( char* s, int len, int want )
{
	int sum = 0;
	for( int i = 0; i < len; ++i )
		sum += i < want? s[ i ] : 0, sum *= i == len-1? 1 : 10;
	return sum;
}

int calc( int N, int target, int div )
{
	char s[ 11 ];
	sprintf( s, "%d", N );
	int len = strlen( s ), ret = 0;

	if( len * 9 < target )
		return 0;

	for( int i = 0; i < len; ++i )
		s[ i ] -= '0';
	for( int i = 0, sum; i < len; ++i ) // length fixed
		for( int j = 0; j < s[ i ]; ++j ) // first digit
			if( ( sum = std::accumulate( s, s+i, 0 ) ) + j <= target )
				ret += sol[ div ][ len-i-1 ][ target - sum - j ][ ( 2*div - calc( s, len, i ) % div - j * pow10[ len-i-1 ] % div ) % div ];
	return ret + ( std::accumulate( s, s+len, 0 ) == target && N % div == 0 );
}

int main()
{
	int t, begin, end, div;

	for( int i = 1; i < 10; ++i )
		pow10[ i ] = 10 * pow10[ i-1 ];
	for( int i = 0; i <= 82; ++i )
		for( int j = 0; j <= 10; ++j )
			sol[ i ][ j ][ 0 ][ 0 ] = 1;
	for( int i = 1; i <= 82; ++i ) // N
		for( int j = 1; j <= 10; ++j ) // # of digits
			for( int k = 1; k <= 82; ++k ) // sum of digits
				for( int l = 0; l < i; ++l ) // modulo of N
					for( int m = 0; m <= 9 && m <= k; ++m ) // first one
						sol[ i ][ j ][ k ][ l ] += sol[ i ][ j-1 ][ k-m ][ ( i + l - m * pow10[ j-1 ] % i ) % i ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d %d", &begin, &end, &div );
		if( div > 82 )
			puts( "0" );
		else
		{
			int ans = 0;
			for( int i = div; i <= 82; i += div )
				ans += calc( end, i, div ) - calc( begin-1, i, div );
			printf( "%d\n", ans );
		}
	}
}
