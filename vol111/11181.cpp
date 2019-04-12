#include<cstdio>

int main()
{
	int bit1[ 1 << 20 ] = { 0 }, man, buy, t = 0;
	double p[ 20 ];

	for( int i = 1; i < 1 << 20; ++i )
		bit1[ i ] = 1 + bit1[ i ^ i & -i ];

	while( scanf( "%d %d", &man, &buy ) && man )
	{
		double up[ 20 ] = { 0 }, down = 0;

		for( int i = 0; i < man; ++i )
			scanf( "%lf", p + i );

		for( int i = 0; i < 1 << man; ++i )
			if( bit1[ i ] == buy )
			{
				double tmp = 1;

				for( int j = 0; j < man; ++j )
					if( 1 << j & i )
						tmp *= p[ j ];
					else
						tmp *= 1 - p[ j ];
				down += tmp;
				for( int j = 0; j < man; ++j )
					if( 1 << j & i )
						up[ j ] += tmp;
			}

		printf( "Case %d:\n", ++t );
		for( int i = 0; i < man; ++i )
			printf( "%f\n", up[ i ] / down );
	}
}
