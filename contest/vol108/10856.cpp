#include<cstdio>
#include<algorithm>
#define S 2703664

int one[ S ] = { 0, 0, 2 }, sum[ S ];

int main()
{
	int n, *pos, t = 0;

	for( long long int i = 3; i < S; i += 2 )
		if( !one[ i ] )
			for( long long int j = i; j < S; j *= i )
				for( int k = j; k < S; k += j )
					++one[ k ];
	for( int i = 2; i < S; i += 2 )
		one[ i ] = one[ i >> 1 ] + 1;
	for( int i = 1; i < S; ++i )
		sum[ i ] = sum[ i-1 ] + one[ i ];

	while( scanf( "%d", &n ) && n >= 0 )
	{
		pos = std::lower_bound( sum, sum+S, n );
		if( *pos == n )
			printf( "Case %d: %d!\n", ++t, pos-sum );
		else
			printf( "Case %d: Not possible.\n", ++t );
	}
}
