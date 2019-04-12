#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long int begin, end, pow2[ 63 ] = { 2 };
	for( int i = 1; i < 63; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;

	while( scanf( "%lld %lld", &begin, &end ) != EOF )
	{
		long long int one = 0;
		for( int i = 0; !i || pow2[ i-1 ] <= end; ++i )
		{
			long long int b = begin + pow2[ i ] - begin % pow2[ i ], e = end - end % pow2[ i ];
			if( e > b )
				one += e - b >> 1;
			if( b - e != pow2[ i ] )
				one += min( pow2[ i ] >> 1, b - begin );
			if( end > e )
				if( e + pow2[ i ] / 2 >= begin )
					one += min( pow2[ i ] >> 1, max( end - e - pow2[ i ] / 2 + 1, 0LL ) );
				else
					one += min( pow2[ i ] >> 1, max( end - begin + 1, 0LL ) );
		}
		printf( "%lld\n", one );
	}

	return 0;
}