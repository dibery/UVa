#include<cstdio>
double p[ 2001 ][ 2001 ];

int main()
{
	p[ 1 ][ 0 ] = 1;
	for( int sum = 2; sum <= 2000; ++sum )
		for( int i = 0; i <= sum; ++i )
		{
			double AB = i * ( sum - i ) / double( sum * ( sum - 1 ) / 2 ), AA = i * ( i - 1 ) / double( sum * ( sum - 1 ) ), BB = ( sum - i ) * ( sum - i - 1 ) / double( sum * ( sum - 1 ) );
			if( i && i < sum )
				p[ i ][ sum - i ] += p[ i - 1 ][ sum - i ] * AB;
			if( i > 1 )
				p[ i ][ sum - i ] += p[ i - 1 ][ sum - i ] * AA;
			if( sum - i > 1 )
				p[ i ][ sum - i ] += p[ i + 1 ][ sum - i - 2 ] * BB;
		}

	int t, a, b;
	scanf( "%d", &t );
	for( int i = 1; i <= t && scanf( "%d %d", &a, &b ); ++i )
		printf( "Case %d: %.3f %.3f\n", i, p[ a ][ b ], ( a + b )? 1 - p[ a ][ b ] : 0 );
}

/* This also works
#include<cstdio>

int main()
{
	int t, a, b;
	
	scanf( "%d", &t );
	for( int i = 1; i <= t && scanf( "%d %d", &a, &b ); ++i )
		if( a + b == 0 )
			printf( "Case %d: 0.000 0.000\n", i );
		else if( b % 2 )
			printf( "Case %d: 0.000 1.000\n", i );
		else
			printf( "Case %d: 1.000 0.000\n", i );
}
*/
