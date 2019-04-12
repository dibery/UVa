#include<cstdio>
#include<cctype>
int cost[ 40 ];

int calc( int n, int base )
{
	int total = 0;
	while( n )
		total += cost[ n % base ], n /= base;
	return total;
}

int main()
{
	int t, test, num;
	scanf( "%d", &t );
	
	for( int n = 1; n <= t; ++n )
	{
		for( int i = 0; i < 36; ++i )
			scanf( "%d", cost + i );
		scanf( "%d", &test );
		printf( "Case %d:\n", n );
		for( int i = 0; i < test; ++i )
		{
			scanf( "%d", &num );
			int need[ 37 ];
			for( int i = 2; i <= 36; ++i )
				need[ i ] = calc( num, i );
			int low = need[ 2 ];
			for( int i = 3; i <= 36; ++i )
				if( need[ i ] < low )
					low = need[ i ];
			printf( "Cheapest base(s) for number %d:", num );
			for( int i = 2; i <= 36; ++i )
				if( need[ i ] == low )
					printf( " %d", i );
			puts( "" );
		}
		if( n != t )
			puts( "" );
	}
}
