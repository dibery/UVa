#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
	for( int size, n[ 300 ], dp[ 300 ][ 300 ], sum[ 300 ]; scanf( "%d", &size ) == 1; )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", n+i );
		fill( dp[ 0 ], dp[ 300 ], INT_MAX );
		fill( sum, sum+300, 0 );
		sum[ 1 ] = n[ 0 ];
		for( int i = 2; i <= size; ++i )
			sum[ i ] = sum[ i-1 ] + n[ i-1 ];
		for( int i = 0; i <= size; ++i )
			dp[ i ][ i ] = dp[ i ][ i+1 ] = 0;
		for( int len = 2; len <= size; ++len )
			for( int b = 0; b + len <= size; ++b )
				for( int m = b; m < b + len; ++m )
					dp[ b ][ b + len ] = min( dp[ b ][ b + len ], dp[ b ][ m ] + sum[ m ] - sum[ b ] + dp[ m + 1 ][ b + len ] + sum[ b+len ] - sum[ m+1 ] );
		printf( "%d\n", dp[ 0 ][ size ] );
	}
}
